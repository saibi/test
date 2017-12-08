/*!
 * \file int.cpp
 * \brief
 *
 *
 * created by Kim Youngmin (ymkim@huvitz.com)
 * creation date : 2017/12/08 11:13:38 (KST)
 *
*/
#include <iomanip>
#include <iostream>

using namespace std;

int main()
{
	int a = -14;
	unsigned int b = 14;

	cout << "a = " << a << ", b = " << b << "\n" ;
	cout << "int(a) = " << int(a) << ", int(b) = " << int(b) << "\n";

	if ( a == int(b) ) 
		cout << "a == b \n" ;
	else
		cout << "a != b \n" ;



	return 0;
}
