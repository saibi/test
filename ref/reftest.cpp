using namespace std;
#include <iostream>
#include <list>


int get_int()
{
	int a = 18;
	int b = 1;

	cout << "a = " << a << " , &a = " << &a << "\n";
	cout << "b = " << b << " , &b = " << &b << "\n";
	return a;
}

list <int> get_int_list()
{
	list <int> list1;

	list1.push_front(1);
	list1.push_front(2);
	list1.push_front(3);
	list1.push_front(4);
	list1.push_front(5);

	list<int>::iterator iterEnd = list1.end();
	for (list<int>::iterator iterPos = list1.begin(); iterPos != iterEnd; ++iterPos) {
		cout << *iterPos << endl;
	}

	return list1;
}

int main()
{
	const int & int_val = get_int();
	const list<int> & list1 = get_int_list();

	cout << "refrence test\n";
	cout << "int_val = " << int_val << " , &int_val = " << &int_val << "\n";

	list<int>::iterator iterEnd = list1.end();
	for (list<int>::iterator iterPos = list1.begin(); iterPos != iterEnd; ++iterPos) {
		cout << *iterPos << endl;
	}

	return 0;
}
