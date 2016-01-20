#include <iostream>

using namespace std;

template <class T>
T mymax(T a, T b)
{
	return a > b ? a : b;
}

int main()
{
	cout << "max(10, 15) = " << mymax(10, 15) << endl;
	cout << "max('k', 's') = " << mymax('k', 's') << endl;
	cout << "max(10.1, 15.2) = " << mymax(10.1, 15.2) << endl;

	return 0;
}
