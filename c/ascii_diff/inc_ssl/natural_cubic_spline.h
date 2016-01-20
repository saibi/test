/*!
 * \file natural_cubic_spline.h
 * \brief
 *
 *
 * created by Kim Hyunju (hjkim@huvitz.com)
 * creation date : ȭ 8 19  ���ѹα� ǥ�ؽ� 2008
 *
*/
#ifndef _NATURAL_CUBIC_SPLINE_H_
#define _NATURAL_CUBIC_SPLINE_H_

#define CUBICSPLINE_STEP    20

typedef struct _CubicSplineCoeff{
	int n ;				// �迭�� ������ �ε���.. ������ �ƴ� �迭�� �ε����̴�...
	float x[CUBICSPLINE_STEP] ;
	float a[CUBICSPLINE_STEP] ;
	float b[CUBICSPLINE_STEP] ;
	float c[CUBICSPLINE_STEP] ;
	float d[CUBICSPLINE_STEP] ;

} CubicSplineCoeff ;

int 	NaturalCubicSpline( float x[], float fn[], int n, CubicSplineCoeff* y );
float 	transfer_pixel_to_diopter( float l , CubicSplineCoeff* y );
float 	transfer_radius_to_encoder( float l , CubicSplineCoeff* y );
int 	find_where_is_x( float x , CubicSplineCoeff* y );

#endif

/********** end of file **********/
