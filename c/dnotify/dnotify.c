/*
Compile this example as follows:

$ gcc dnotify.c -o dnotify

Now, if you modify anything in the current directory, you'll
see results.

Example download:
http://ftp1.sourceforge.net/cpearls/simple_but_common.tar.gz

Also see Linux kernel
Documents/dnotify.txt

*/



#define _GNU_SOURCE     /* needed to get the defines */
#include <fcntl.h>      /* in glibc 2.2 this has the needed values defined */
#include <signal.h>
#include <stdio.h>
#include <unistd.h>

#include <sys/types.h>
#include <dirent.h>

/// directory listing
/// \param path
static void ls(char *path)
{
	DIR *pdir;
	struct dirent *dentry;

	pdir = opendir(path);
	if ( pdir == NULL ) {
		perror("opendir error");
		return;
	}


	for(;;) {
		dentry = readdir(pdir);
		if (dentry == NULL ) {
			break;
		}
		printf("%s\n", dentry->d_name);
	}

	closedir(pdir);
}

static volatile int event_fd;
static volatile int event_sig;
static volatile void *event_data;

static void handler(int sig, siginfo_t *si, void *data)
{
	event_fd = si->si_fd;
	event_sig = sig;
	event_data = data;
}

int main(void)
{
	struct sigaction act;
	int fd;

	act.sa_sigaction = handler;
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_SIGINFO;
	sigaction(SIGRTMIN + 1, &act, NULL);

	fd = open(".", O_RDONLY);
	fcntl(fd, F_SETSIG, SIGRTMIN + 1);
	//fcntl(fd, F_NOTIFY, DN_ACCESS|DN_MODIFY|DN_CREATE|DN_RENAME|DN_DELETE|DN_ATTRIB|DN_MULTISHOT);
	fcntl(fd, F_NOTIFY, DN_CREATE|DN_MULTISHOT);
	/* we will now be notified if any of the files in "." is modified or new files are created */
	while (1) {
		pause();
		printf("Got event on fd=%d, sig=%d, data=%p\n", event_fd, event_sig, event_data);
		ls(".");
	}
}


