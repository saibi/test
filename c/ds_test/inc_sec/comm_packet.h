/*!
 * \file comm_packet.h
 * \brief
 *
 *
 * created by Kim Youngmin (ymkim@huvitz.com)
 * creation date : ��  7�� 13 09:59:16 KST 2007
 *
*/
#ifndef _COMM_PACKET_H_
#define _COMM_PACKET_H_

#include <string.h>
#include <iso16284_char_def.h>
#include <send_packet.h>
#include <comm_base.h>



// packet size 
#define SMALL_PACKET_SIZE 2048 // 20100211 ũ�⸦ 1024 ���� 2048 �� ������ 
#define BIG_PACKET_SIZE 30000 // data packet �� ���� �޸� ũ�� 


// ��Ŷ ���� OK
#define PFMT_ACK \
	"<ACK>" 

// ��Ŷ ���� ����
#define PFMT_NAK \
	"<NAK>" 


int check_packet_crc(int uart, char *buf, int size);
int send_packet_with_crc(int uart, char *buf, int size);
int send_small_asc_iso16284_packet(int uart, char *buf);
int send_small_asc_iso16284_packet_with_crc(int uart, char *buf);
int send_user_define_packet(int uart, char *line);
int send_fmt_packet(int uart, char *fmt, ...);
void send_nak(int uart);
void send_ack(int uart);

// comm_check_crc.c
int check_packet_buffer_crc(char *packet, int packet_size);
#endif
/********** end of file **********/
