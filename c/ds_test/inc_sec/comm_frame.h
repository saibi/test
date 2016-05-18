/*!
 * \file comm_frame.h
 * \brief
 *
 *
 * created by Kim Youngmin (ymkim@huvitz.com)
 * creation date : ��  7�� 05 12:12:49 KST 2006
 *
*/
#ifndef _COMM_FRAME_H_
#define _COMM_FRAME_H_

#include "iso16284_char_def.h"
#include "common_macro.h"



// iso16284 packet
// ascii �������� ���������� �ۼ��� ���� 
// �ֿ� ������ parameter �� �Է� �޾�
// binary �� ��ȯ�ؼ� �������� �Ѵ�.
//
// ��� ���� _js �� �ʿ��� parameter �� �� ǥ���Ѵ�.


// data �� �����״� �غ��ض�
// ����� ȣȯ�� ���� <ACK> �� �߰��� c8c8c8
#define PFMT_REQ_SEND_j 	\
	"<FS>" \
	"REQ=TRC<CR>" \
	"JOB=%s<CR>" \
	"<GS>"


// data ������
// ���� �Լ��� �̿��� ������ ä���. epc_frame_data_to_iso16284() ����
#define PFMT_SEND_DATA_HEADER_rj \
	"<FS>" \
	"ANS=%s<CR>" \
	"JOB=%s<CR>" 

#define PFMT_SEND_DATA_FOOTER \
	"<GS>"


// ������ data �� �����޶� 
#define PFMT_REQ_RECEIVE \
	"<FS>" \
	"REQ=EDG<CR>" \
	"<GS>"

// ������ data �� �����޶� (job no ����) 
#define PFMT_REQ_RECEIVE_j \
	"<FS>" \
	"REQ=EDG<CR>" \
	"JOB=%s<CR>" \
	"<GS>"

///////////////////////////////////////


// data�� ���� �� �ִ�.
#define PFMT_ANS_SEND_OK_rjs \
	"<FS>" \
	"ANS=%s<CR>" \
	"JOB=%s<CR>" \
	"STATUS=%d<CR>" \
	"<GS>"


// data �� �޾Ҵ�.
// 20070402 status �ʵ� �߰���  
// PFMT_ANS_SEND_OK_rjs �� �����ϱ� 
// ������ ����� �ϴ� ����ó��  ��Ŷ�� �����ؼ� ����� ��
#define PFMT_RECEIVE_OK_rjs \
	"<FS>" \
	"ANS=%s<CR>" \
	"JOB=%s<CR>" \
	"STATUS=%d<CR>" \
	"<GS>"


// 20070319 CRC �� ��� �Լ������� ó���ϵ��� ������ 
//	"<RS>" 
//	"CRC=%s<CR>" 






/*
 
// protocol example 

tracer -> edger data ���� 

EDGER			TRACER
----------------------------------------------------------------
			REQ_SEND
ANS_SEND_OK
			SEND_DATA
RECEIVE_OK




edger -> tracer data ���� 

EDGER			TRACER
----------------------------------------------------------------
REQ_SEND
			ANS_SEND_OK
SEND_DATA
			RECEIVE_OK



edger <- tracer data ��û

EDGER			TRACER
----------------------------------------------------------------
REQ_RECEIVE
			SEND_DATA

*/



int send_frame_data(int uart, char *job_no, struct epc_frame_data *frame, int frame_count);
int recieve_pure_frame_data(int uart, char *job_no, struct epc_frame_data *frame, int frame_count);
int request_frame_data(int uart, char *job_no, struct epc_frame_data *frame, int frame_count);
int request_frame_data_ex(int uart, char *job_no, struct epc_frame_data *frame, int frame_count);
int receive_frame_data(int uart, char *job_no, struct epc_frame_data *frame, int frame_count);
int send_pure_frame_data(int uart, char * request_type, char *job_no, struct epc_frame_data *frame, int frame_count);

#define SFDF_OLD_CPE_4000 0x01
void set_send_frame_data_option(int flag);

#endif
/********** end of file **********/
