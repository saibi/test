#include <iostream>

#include <climits>

int main()
{
	using namespace std;

	int n_int = INT_MAX;
	long long n_llong = LLONG_MAX;
	
	cout << "int " << sizeof (int) << " " << n_int << endl;
	cout << "long long " << sizeof n_llong << " " << n_llong << endl;

	return 0;
}

