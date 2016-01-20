/*!
 * \file int_float.h
 * \brief
 *
 * int Ÿ������ �Ǽ� ���� ����ϱ� ���� ��ũ��
 *
 * created by Kim Youngmin (ymkim@huvitz.com)
 * creation date : ��  1�� 31 15:27:10 KST 2007
 *
*/
#ifndef _INT_FLOAT_H_
#define _INT_FLOAT_H_

#define MIN_INT_FLOAT_PLACE 1
#define MAX_INT_FLOAT_PLACE 9

extern float f_int_float_div_list[MAX_INT_FLOAT_PLACE+1];

#define FLOAT_TO_INT_FLOAT(fvalue, place) (int)((fvalue) * f_int_float_div_list[place])
#define INT_FLOAT_TO_FLOAT(ivalue, place) (float)((ivalue) / f_int_float_div_list[place])

#endif 
/********** end of file **********/
