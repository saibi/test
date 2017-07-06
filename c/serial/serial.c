#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>

#include "serial.h"

struct iso16284_code_to_str iso16284_string_table[] = { 
	{ CHAR_CR, "<CR>", 4 },
	{ CHAR_FS, "<FS>", 4},
	{ CHAR_GS, "<GS>", 4 },
	{ CHAR_ACK, "<ACK>", 5 },
	{ CHAR_NAK, "<NAK>", 5 },
	{ CHAR_RS, "<RS>", 4 },
	{ CHAR_LF, "<LF>", 4 },
	{ CHAR_ESC, "<ESC>", 5 },
	{ -1, "<CR/LF>", 7 },
	{ -1, NULL, -1 },
};

/// iso16284 통신 stream 출력 
/// \param addr source buf pointer (null-terminated string)
/// \param max
void print_iso16284_stream_ex(void *addr, int max)
{
	char * ptr = (char *)addr;
	int reserved = 0;
	int i, counter;

	for ( counter = 0 ; *ptr && counter < max ; ptr++, counter++ ) {
		for ( i = 0 ; iso16284_string_table[i].code >= 0; i++) {
			if ( iso16284_string_table[i].code == *ptr ) {
				fputs(iso16284_string_table[i].str, stdout);
				if ( *ptr != CHAR_ESC ) {
					fputs("\n", stdout);
				}
				reserved = 1;
				break;
			}
		}
		if ( !reserved )  {
			if ( (*ptr < ' ') || (*ptr >= 127) ) {
				fprintf(stdout, "\\%02X", (unsigned int)*ptr);	
			} else {
				fputc(*ptr, stdout);
			}
		}
		reserved = 0;
	}
}

int set_interface_attribs(int fd, int speed)
{
	struct termios tty;

	if (tcgetattr(fd, &tty) < 0)
	{
		printf("Error from tcgetattr: %s\n", strerror(errno));
		return -1;
	}

	cfsetospeed(&tty, (speed_t) speed);
	cfsetispeed(&tty, (speed_t) speed);

	tty.c_cflag |= (CLOCAL | CREAD);	/* ignore modem controls */
	tty.c_cflag &= ~CSIZE;
	tty.c_cflag |= CS8;	/* 8-bit characters */
	tty.c_cflag &= ~PARENB;	/* no parity bit */
	tty.c_cflag &= ~CSTOPB;	/* only need 1 stop bit */
	tty.c_cflag &= ~CRTSCTS;	/* no hardware flowcontrol */

	/* setup for non-canonical mode */
	tty.c_iflag &= ~(IGNBRK | BRKINT | PARMRK | ISTRIP | INLCR | IGNCR | ICRNL | IXON);
	tty.c_lflag &= ~(ECHO | ECHONL | ICANON | ISIG | IEXTEN);
	tty.c_oflag &= ~OPOST;

	/* fetch bytes as they become available */
	tty.c_cc[VMIN] = 1;
	tty.c_cc[VTIME] = 1;

	if (tcsetattr(fd, TCSANOW, &tty) != 0)
	{
		printf("Error from tcsetattr: %s\n", strerror(errno));
		return -1;
	}
	return 0;
}

void set_mincount(int fd, int mcount)
{
	struct termios tty;

	if (tcgetattr(fd, &tty) < 0)
	{
		printf("Error tcgetattr: %s\n", strerror(errno));
		return;
	}

	tty.c_cc[VMIN] = mcount ? 1 : 0;
	tty.c_cc[VTIME] = 5;	/* half second timer */

	if (tcsetattr(fd, TCSANOW, &tty) < 0)
		printf("Error tcsetattr: %s\n", strerror(errno));
}

unsigned char buf[MAX_BUF];

int main(int argc, char *argv[])
{
#ifdef __arm__
	char *portname = "/dev/ttyS2";
#else 
	char *portname = "/dev/ttyUSB0";
#endif 
	int fd;
	int wlen;

	fd = open(portname, O_RDWR | O_NOCTTY | O_SYNC);
	if (fd < 0)
	{
		printf("Error opening %s: %s\n", portname, strerror(errno));
		return -1;
	}
	/*baudrate 115200, 8 bits, no parity, 1 stop bit */
	set_interface_attribs(fd, B115200);
	//set_mincount(fd, 0);                /* set to pure timed read */

	/* simple output */
	wlen = write(fd, "Hello!\n", 7);
	if (wlen != 7)
	{
		printf("Error from write: %d, %d\n", wlen, errno);
	}
	tcdrain(fd);	/* delay for output */

	/* simple noncanonical input */
	do
	{
		int rdlen;

		rdlen = read(fd, buf, sizeof(buf) - 1);
		if (rdlen > 0)
		{
			print_iso16284_stream_ex(buf, rdlen);
			fflush(stdout);

#if 0
#ifdef DISPLAY_STRING
			buf[rdlen] = 0;
			printf("Read %d: \"%s\"\n", rdlen, buf);
#else /* display hex */
			unsigned char *p;
			printf("Read %d:", rdlen);
			for (p = buf; rdlen-- > 0; p++)
				printf(" 0x%x", *p);
			printf("\n");
#endif
#endif 
		} else if (rdlen < 0)
		{
			printf("Error from read: %d: %s\n", rdlen, strerror(errno));
		}
		/* repeat read to get full message */
	} while (1);
}

