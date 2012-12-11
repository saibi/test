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
	float dvalue = 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1;

	float fvalue1 = 1.345f;
	float fvalue2 = 1.123f;
	float ftotal = fvalue1 + fvalue2;

	result = lotto - tax;
	printf("tax = %f\n", tax);
	printf("result = %f\n", result );

	printf("dvaule = %.17f\n", dvalue);

	printf("ftotal = %.20f\n", ftotal);

	if ( ftotal == 2.468 ) 
		printf("ok\n");
	else 
		printf("error\n");

	return 0;
}
/********** end of file **********/
