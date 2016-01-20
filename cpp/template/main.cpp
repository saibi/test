#include <iostream>
#include "stack.h"
using namespace std;

int main()
{
	typedef Stack<float> FloatStack;
	typedef Stack<int> IntStack;

	FloatStack fs(5);
	float f = 1.1;

	cout << "Pushing element into fs" << endl;
	while (fs.push(f))
	{
		cout << f << ' ';
		f += 1.1;
	}

	cout<< endl << "Stack Full" << endl;

	while (fs.pop(f))
		cout << f <<' ';
	cout << endl << "Stack Error" << endl;
	cout << endl;
	return 0;
}
