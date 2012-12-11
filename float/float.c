/*!
  \file float.c
  \brief


  created by Kim Youngmin (ymkim@huvitz.com)
  creation date : ȭ 12 11 18:42:43 KST 2012

*/
#include <stdio.h>


/// tester main
int main(void)
{
	double lotto = 1.0e10;
	double tax = lotto * 33.0/100.0;
	double result;

	result = lotto - tax;
	printf("tax = %f\n", tax);
	printf("result = %f\n", result );


	return 0;
}
/********** end of file **********/
