/*!
 * \file error.h
 * \brief
 *
 * error code 
 *
 * created by Kim Youngmin (ymkim@huvitz.com)
 * creation date : ��  6�� 12 20:31:10 KST 2006
 *
*/

#ifndef _ERROR_H_
#define _ERROR_H_

#define ERR_NONE 0

enum error_idx {
	ERR = 100000,
	ERR_MAX, // �ִ밪 �ʰ�
	ERR_MIN, // �ּҰ� �̸�
	ERR_MODIFY, // �� ���� �Ұ�
	ERR_MEM, // memory ����
	ERR_NOMEM, // same as ERR_MEM
	ERR_INVAL, // invalid paramerter, value, 
	ERR_IO, // i/o ����
	ERR_READ, // read ����
	ERR_WRITE, // write ����
	ERR_FULL, // buffer full /

	ERR_IMPL, // not implemented // 11
	ERR_NOENT, // �ش� �׸� ����
	ERR_TIMEOUT, // time out
	ERR_NOT_READY, // not ready
	ERR_EOF, // end of file, end of buffer, end of string
	ERR_TYPE, // type mismatch
	ERR_FORMAT, // invalid format
	ERR_OVERFLOW, // over flow
	ERR_EMPTY, // empty 
	ERR_EDGING, // ���� ���� 

	ERR_DUP, // �ߺ� ���� // 21
	ERR_DIV_BY_ZERO,  // division by zero
	ERR_VERIFY, // verify failed
	ERR_NOT_ORIGIN, // motor ���� ����
	ERR_STOP, // user stop 
	ERR_PERM, // permission error
	ERR_MAX_EDGING_TIME, // �ִ� ���� �ð� �ʰ�
	ERR_BUSY, // �����
	ERR_WPROTECT, // write protected

	MAX_ERR
};


#endif
/********** end of file **********/
