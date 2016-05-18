/*!
 * \file comm_base.h
 * \brief
 *
 * 20070326 comm_common.h ���� comm_base.h �� �̸� ���� (cpe gui old ��� �ڵ�� �ߺ��Ǵ� �����̸��̶�...)
 *
 * created by Kim Youngmin (ymkim@huvitz.com)
 * creation date : ��  3�� 26 21:53:37 KST 2007
 *
*/
#ifndef _COMM_BASE_H_
#define _COMM_BASE_H_

#include "llist.h"

/// uart ���� ���� ũ�� 
#define COMM_UART_BUF_SIZE (128*1024) // 128KB, ���� full frame �� ���۵ɶ� �� 25000bytes ������ ���۵ȴ�.

#define COMM_TIMEOUT_DURATION 12 // ��� Ÿ�Ӿƿ� 12�� 

// ��� �ɼ� 
#define COMM_OPTION_GEN_CRC 0x01 // ��Ŷ ���۽� CRC �߰� 
#define COMM_OPTION_CHECK_CRC 0x02 // ��Ŷ ���Ž� CRC �˻�
#define COMM_OPTION_DUMP_SEND_PACKET 0x04 // ��Ŷ ���۽� ���� dump
#define COMM_OPTION_DUMP_RECV_PACKET 0x08 // ��Ŷ ���Ž� ���� dump
#define COMM_OPTION_STRICT_CRC_CHECK 0x10 // FM ��� CRC �˻� (COMM_OPTION_CHECK_CRC �� ���ǵ� ���¿����� �����Ѵ�)

// ��Ŷ ������ ���� ����� ���� uart flag
#define COMM_BUF_FLAG_PACKET_RECEIVED 0x1000
#define COMM_BUF_FLAG_ACK_RECEIVED 0x2000
#define COMM_BUF_FLAG_PACKET_START 0x4000
#define COMM_BUF_FLAG_BARCODE 0x8000 // barcode uart �� ��� ���� 
#define COMM_BUF_FLAG_INVALID_GS 0x010000 // invalid GS ���� ǥ��

struct comm_uart_handler_rec {
	int comm_buffer_flag;
	struct list_head received_packet_list;
	struct list_head used_packet_list; // �̹� ó���� ��Ŷ
	int comm_uart_buf_size;
	int (*packet_scan_function)(char *, int, char**);
	struct comm_packet *recent_packet;
	void * comm_time_loop_handler;

	// default timeout (����: ��)
	int default_comm_timeout_second;

	// ��� �ɼ�
	int default_comm_option;

	// nak ����� ��õ� Ƚ��
	int default_comm_retry_count;
};



// ��Ŷ Ÿ�� �˻縦 ���� table ����ü
struct packet_type_strmap {
	char *str;
	int type;
};


// ��Ŷ ����ü
struct comm_packet {
	int type; 
	int size;
	unsigned int time;
	void *extra; // ��Ÿ �ΰ� ���� ����� �ʵ� (�޸𸮸� �Ҵ��ؼ� ������, int ������ ������ ��Ȳ�� ���� �˾Ƽ� ����)
			// 20070402 extra �ʵ忡 packet type scan ������ ����
	struct list_head list;

	char buf[ZERO_ARRAY_IDX]; // �� �ʵ�� memory ��ġ�� �˱����� 
				// dummy �������̴�.
				// salloc() ���� �޸𸮸� �Ҵ��Ҷ� 
				// ���� ũ�� ���� �����ϵ��� �Ѵ�.
				//
				// sdt 2.5 ���� xx[0] ���� ����
				// xx[1] �� ��ü
};

extern struct comm_uart_handler_rec *comm_uart_data;

int init_comm_data(int max );
void set_packet_scanner(int uart, int (*func)(char *, int, char **) ) ;
void set_comm_uart_buf_size(int uart, int size);
int init_comm_uart_handler(int uart, int (*)(char *, int, char**) );
void free_comm_uart_handler(int uart);
void packet_receiver(int uart, char ch);
int get_current_packet_count(int uart);


#define GET_RECENT_PACKET(no) (comm_uart_data[no].recent_packet)

#define free_barcode_uart_handler(uart) free_comm_uart_handler(uart)



/// ��Ŷ�� �����ϱ� ���� �ߴ°�?
#define IS_PACKET_START(no) (comm_uart_data[no].comm_buffer_flag & COMM_BUF_FLAG_PACKET_START)

/// ��Ŷ�� ���� �����ߴ°�?
#define IS_PACKET_RECEIVED(no) (comm_uart_data[no].comm_buffer_flag & COMM_BUF_FLAG_PACKET_RECEIVED)

/// ack ��Ŷ�� �����ߴ°�?
#define IS_ACK_RECEIVED(no) (comm_uart_data[no].comm_buffer_flag & COMM_BUF_FLAG_ACK_RECEIVED)

/// barcode uart �ΰ� ?
#define IS_BARCODE_UART(no) (comm_uart_data[no].comm_buffer_flag & COMM_BUF_FLAG_BARCODE)


/// flag ���� 
#define SET_COMM_BUFFER_FLAG(no, flag) comm_uart_data[no].comm_buffer_flag |= (flag)
#define SET_COMM_BUFFER_FLAG_VALUE(no, value) comm_uart_data[no].comm_buffer_flag = (value)
/// flag ����
#define CLEAR_COMM_BUFFER_FLAG(no, flag) comm_uart_data[no].comm_buffer_flag &= (~(flag))



/// ��� time loop handler ���� 
/// \param handler
static INLINE void set_comm_time_loop_handler(int uart, void *handler) 
{
	comm_uart_data[uart].comm_time_loop_handler = (void*)handler;
}

/// ��� time loop handler ���� 
static INLINE void clear_comm_time_loop_handler(int uart)
{
	comm_uart_data[uart].comm_time_loop_handler = NULL;
}


/// time out loop handler ����
/// \return 0 �̸� loop ��� ���� 
/// \return ���� loop �ߴ��� �� 
static INLINE int RUN_COMM_TIME_LOOP_HANDLER(int uart) 
{
	if ( comm_uart_data[uart].comm_time_loop_handler ) { 
		return ((int (*)(void))comm_uart_data[uart].comm_time_loop_handler)();
	} 
	return 0;
}

/// ��Ŷ ��/���� �ÿ� ����� timeout ���� (�ʴ���)
/// ȣ�� Ƚ���� ������� �ʾ� �Լ��� ó����
/// \param val timeout
static INLINE void set_default_comm_timeout( int uart, int val ) 
{
	//ASSERT( val >= 0 );

	comm_uart_data[uart].default_comm_timeout_second = val;
}

/// ��Ŷ ��/���ſ� timeout ����
/// \return timeout
static INLINE int get_default_comm_timeout(int uart)
{
	return comm_uart_data[uart].default_comm_timeout_second;
}


/// ��ſ��� �߻��� (���� ACK ��ſ� NAK ���� �޾��� ���) ��õ� Ƚ�� ����
/// \param uart
/// \param val ��õ� Ƚ��
static INLINE void set_default_comm_retry_count( int uart, int val ) 
{
	//ASSERT( val >= 0 ) ;
	comm_uart_data[uart].default_comm_retry_count = val;
}

/// ��� ��õ� Ƚ�� ����
/// \param uart
/// \return retry_count
static INLINE int get_default_comm_retry_count(int uart)
{
	return comm_uart_data[uart].default_comm_retry_count;
}

/// ��� �ɼ� ���� 
/// \param uart
/// \param val ��� �ɼ�,  see comm_frame.h #define COMM_OPTION_xxxx 
static INLINE void set_default_comm_option ( int uart, int val )
{
	comm_uart_data[uart].default_comm_option = val;
}

/// ��� �ɼ� ����
/// \param uart
/// \return option
static INLINE int get_default_comm_option(int uart)
{
	return comm_uart_data[uart].default_comm_option;
}

/// ���� ��Ŷ ����Ʈ head pointer ���� 
/// \return list_head
static INLINE struct list_head * get_received_packet_list_head(int uart)
{
	return &comm_uart_data[uart].received_packet_list;
}

/// ��� ���� �÷��� ����
/// \return flag
static INLINE int get_comm_buffer_flag(int uart)
{
	return comm_uart_data[uart].comm_buffer_flag;
}








// comm_build.c
void set_barcode_parsing_func(void *func);
struct comm_packet * make_packet(int uart, char *buf, int size, int type);
int parsing_comm_handler_buffer_and_make_packet(int uart, char *buf, int max);
void build_received_packet(int uart);
int get_request_type_str(char *packet_buf, char *buf);
int get_received_packet(int uart, char *request_type, char **buf, int *size);
void free_received_packet(int uart);
void free_used_packet(int uart);
struct comm_packet * search_received_packet(int uart, int type);
void delete_packet(struct comm_packet *p);


// comm_emul.c
int sec_add_comm_packet(int uart, char *buf, int size);
int sec_emulate_simple_comm_packet(int uart, char *packet_str);


// comm_parse.c
int get_packet_value(char *buf, char *value);
int get_job_str(char *packet_buf, char *buf);
int get_packet_status_code(char *packet_buf);

// comm_rcv.c
int recv_packet(int uart, int packet_type, int time_out);

// comm_pr_stat.c
void pr_comm_uart_status(int uart);

#endif
/********** end of file **********/
