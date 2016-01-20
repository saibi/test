/*!
 * \file bin2bhc.c
 * \brief
 *
 *
 * created by Kim Youngmin (ymkim@huvitz.com)
 * creation date : �� 6 01  ���ѹα� ǥ�ؽ� 2009
 *
*/
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

/// checksum ��� 
/// \param buf 
/// \param size
/// \return checksum
static int calc_checksum(unsigned char *buf, int size)
{
	unsigned short checksum = 0;
	int i;

	for ( i = 0; i < size ; i++) {
		checksum += buf[i];
	}
	return checksum;
}


/// file �б� (GB �̻��� ū ���� ó�� ����)
/// \param fd file descriptor
/// \param buf (out) ���� ������ ����� ���� (����� �޸� Ȯ���ؾ��Ѵ�)
/// \param size
/// \return file size
/// \return ���� ���� 
static int read_file(int fd, unsigned char *buf, int size)
{
	int rd_idx = 0;
	int ret;

	while( rd_idx < size ) {
		ret = read(fd, &buf[rd_idx], size);
		if ( ret <= 0 ) {
			break;
		}
		rd_idx += ret;
		size -= ret;
	}
	if ( ret < 0 ) {
		return ret;
	}
	return rd_idx;
}

/// file ���� (GB �̻��� ū ���� ó�� ����)
/// \param fd file descriptor
/// \param buf (in) �� ���� ����
/// \param size
/// \return file size
/// \return ���� ���� 
static int write_file(int fd, unsigned char *buf, int size)
{
	int wr_idx = 0;
	int ret;

	while( wr_idx < size ) {
		ret = write(fd, &buf[wr_idx], size);
		if ( ret <= 0 ) {
			break;
		}
		wr_idx += ret;
		size -= ret;
	}
	if ( ret < 0 ) {
		return ret;
	}
	return wr_idx;
}

/// .bhc ���� �̸� ���� 
/// \param ���� ���� �̸� 
/// \return .bhc ���� �̸� 
static char *make_outfile(char *in)
{
	static char tmp[1024];
	char *p;

	strncpy(tmp, in, sizeof(tmp));

	if ( (p = strrchr(tmp, '.')) == NULL ) {
		strcat(tmp, ".bhc");
	} else {
		*p = 0;
		strcat(tmp, ".bhc");
	}
	return tmp;
}



/// ���� ���α׷�
int main(int argc, char *argv[])
{
	int fd;
	unsigned char *buf;
	struct stat sb;
	unsigned int new_sz;
	unsigned short new_checksum;
	char *nf;

	printf("Converting .bin -> .bhc \n");

	// parameter check
	if ( argc < 2 ) {
		printf("usage : %s filename\n", argv[0]);
		exit(1);
	}

	// ���� ���� ����
	fd = open(argv[1], O_RDONLY);
	if ( fd < 0 ) {
		printf("file open error %s.\n", argv[1]);
		exit(2);
	}

	// ������ ���� ���
	if ( fstat(fd, &sb) < 0 ) {
		printf("stat error %s\n", argv[1]);
		exit(3);
	}

	// �޸� Ȯ��
	buf = (unsigned char *)malloc( sb.st_size + 1);
	if ( buf == NULL ) {
		printf("memory error.\n");
		exit(4);
	}

	// ���� ���� 
	if ( read_file(fd, buf, sb.st_size) < 0 ) {
		printf("read error %s\n", argv[1]);
		exit(5);
	}
	close(fd);


	// ������ size �� checksum ���  
	new_sz = sb.st_size + sizeof(int) + sizeof(short); // 4bytes(total size) +���������� + 2bytes(checksum)
	new_checksum = calc_checksum(buf, sb.st_size); // check ���

	printf("file %s, size = %d, out_size = %d, crc = %x\n", argv[1], (int)sb.st_size, new_sz, new_checksum);

	// ��ȯ ���� ���� 
	fd = creat( (nf = make_outfile(argv[1])), S_IRWXU | S_IRWXG | S_IRWXO); 
	if ( fd < 0 ) {
		printf("file creation error %s.\n", nf);
		exit(6);
	}

	// ���� ��� (total size = 4 + ���� ������ + 2 )
	if ( write(fd, &new_sz, sizeof(int)) < 0 ) {
		printf("write error. (size)\n");
		exit(7);
	}

	// ���� ��� (����)
	if ( write_file(fd, buf, sb.st_size) < 0 ) {
		printf("write error %s\n", nf);
		exit(8);
	}

	// ���� ��� (checksum)
	if ( write(fd, &new_checksum, sizeof(short)) < 0 ) {
		printf("write error. (checksum)\n");
		exit(9);
	}
	close(fd);

	printf("%s created.\n", nf);
	exit(0);
}
/********** end of file **********/
