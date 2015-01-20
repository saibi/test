#include <iostream>
#include <stdio.h>

using namespace std;

//int sum(int a, int b)
//{
//	printf("int\n");
//	return a+b;
//}

//float sum(float a, float b)
//{
//	printf("float\n");
//	return a+b;
//}

int main()
{
	const int val = 7;

	const int *p = &val;


	int val2;

	int * const p2 = &val2;

	val2 = 2;

	p = &val2;

	p2 = 0;


//	printf("sum = %f\n", sum(1.0f, 2.0f));


//	cout << "Hello World!" << endl;

//	const char * const p  = "12345";
//	const char *p2 = "678";

//	printf("p = %s\n", p);

//	p = p2;

//	//p[0] = 'a';

//	printf("p = %s\n", p);



//	char p[1024][1025];

//	p[0][0] = 0;
//	p[1023][1024] = 0;

//	int iArray1[4];
//	int iArray2[4];
//	int iArray3[4];


//	printf("%p %p %p\n", iArray1, iArray2, iArray3);
//	printf("%p %p %p\n", &iArray1[5], &iArray2[5], &iArray3[5]);

//	for ( int i = 0 ; i < 5 ; i++)
//		iArray3[i] = i;

//	for ( int i = 0 ; i <= 5 ; i++)
//		iArray2[i] = i;

//	for (int i = 0 ; i <= 5 ; i++)
//		iArray1[i] = i;


//	for ( int i = 0 ; i < 5 ; i++)
//		printf("iArray1[%d] = %d\n", i, iArray1[i]);

//	for ( int i = 0 ; i < 5 ; i++)
//		printf("iArray2[%d] = %d\n", i, iArray2[i]);

//	for ( int i = 0 ; i < 5 ; i++)
//		printf("iArray3[%d] = %d\n", i, iArray3[i]);


//	int iArray[5];

//	printf("iArray : %p\n", iArray);
//	printf("&iArray : %p\n", &iArray);



//	int x;
//	int y;
//	int iResult;

//	printf("&x : %p\n", &x);
//	printf("&y : %p\n", &y);
//	printf("&iResult : %p\n", &iResult);

//	x = 10;
//	y = 20;
//	iResult = x + y;

//	printf("%d + %d = %d\n", x, y, iResult);





//	int (*p)();
//	p = main;
//	printf("&main = %p\n", p);
	return 0;
}

