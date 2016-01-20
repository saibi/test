using namespace std;
#include <iostream>

class test {


public:
	int a, b;

	test();
	~test();

};

test::test()
{
	a = 0;
}

test::~test()
{
	b = 0;
}

int main(int argc, char *argv[])
{
	test hoho;

	cout << hoho.a << "    " << hoho.b << endl;

	return 0;
}
