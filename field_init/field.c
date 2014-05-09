/*!
  \file field.c
  \brief


  created by Kim Youngmin (ymkim@huvitz.com)
  creation date : 2014/05/09 15:50:12 (KST)

*/
#include <stdio.h>

struct test_struct
{
	int array[2];
	int value;
};

struct test_struct a =
{
	.array[0] = 0,
	.array[1] = 1,
	.value = 10,
};

int main(void)
{
	printf("array[1] = %d\n", a.array[1]);

	return 0;
}
/********** end of file **********/
