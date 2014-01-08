#include <iostream>

using namespace std;

class test {
	public:
		int a;
		int b;

		void pr1();

	protected:
		int c;
		int d;

		void pr2();
};

void test::pr1()
{
	a = 1;
	b = 2;

	cout << a << b;
}

void test::pr2()
{
	c = 4;
	d = 5;

	cout << c << d;
}


int main(void)
{
	class test ttt;
	
	
	ttt.pr1();
	ttt.pr2();
	return 0;
}
