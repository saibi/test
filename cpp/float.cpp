/*!
  \file float.cpp
  \brief


  created by Kim Youngmin (ymkim@huvitz.com)
  creation date : 수 12 12 14:02:54 KST 2012

*/

#include <iomanip>
#include <iostream>

using namespace std;

int main()
{
	//cout << setprecision(17);

	float score1 = 1.345;
	float score2 = 1.123;
	float total = score1 + score2;

	if ( total == 2.468f) {
		cout << "2.468" << endl;
	} else if ( total > 2.468f ) {
		cout << "big" << endl;
	} else {
		cout << "small" << endl;
	}

	if ( score1 == 1.345) {
		cout << "1.345" << endl;
	} else {
		cout << "not" << endl;
	}

#if 0
	double dValue = 0.1;
	float fvalue = 0.1;

	cout << dValue << endl;
	cout << fvalue << endl;

#endif 
	return 0;
}
