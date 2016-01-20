/*!
 * \file salloc.h
 * \brief
 * simple memory allocation
 *
 * created by Kim Youngmin (ymkim@huvitz.com)
 * creation date : ��  4�� 03 13:53:01 KST 2006
 *
*/

#ifndef _SALLOC_H_
#define _SALLOC_H_


#define SALLOC_MAGIC 0x20118279 // 20070209 �޴��� �ٲ��.

/// simple allocation stub structure
struct salloc_stub {
	unsigned int magic;
	unsigned int size;
	unsigned int id; // �޸� ���� ������ ���� id
	struct salloc_stub *next, *prev;
};


int init_salloc(void *start_address, unsigned int pool_size);
void * salloc(unsigned int req_size);
int sfree(void *req_mem);
void *srealloc(void *req_addr, unsigned int resize);
void * scalloc(unsigned int req_size);
void * salloc_get_next_address(void);

// �̸� ���� strdup �� ǥ�� library �Լ� �̸��̶� �տ� s �ϳ� �� ����
char * sstrdup(char *src);

// _DEBUG_ ���� �������� ��� �Ʒ� �Լ� ��� ���� 
void stat_salloc(void);
void show_salloc_addr(void);
void show_salloc_list(int);

#endif // _SALLOC_H_
/********** end of file **********/
