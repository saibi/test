/*!
 * \file point_in_polygon.h
 * \brief
 *
 *
 * created by Kim Youngmin (ymkim@huvitz.com)
 * creation date : �� 7 02  ���ѹα� ǥ�ؽ� 2008
 *
*/
#ifndef _POINT_IN_POLYGON_H_
#define _POINT_IN_POLYGON_H_

typedef struct point_rec {
	int x;
	int y;
} POINT;

int point_in_polygon(POINT *xylist, int record_number, int px, int py);

#endif
/********** end of file **********/
