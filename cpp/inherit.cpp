#include <iostream>
using namespace std;

class parent 
{
public:
	parent();

	void setFlag(bool flag) { m_flag = flag; }

protected:
	bool m_flag;
	int m_data;

	virtual void init();
};

parent::parent()
{
	init();

	cout << "m_flag = " << m_flag << "\n";
	cout << "m_data= " << m_data << "\n";
}

void parent::init()
{
	cout << "parent::init\n"; 

	m_flag = false;
	m_data = 18;
}


class child : public parent
{
public:
	child();

	void setValue(int val) { m_value = val; }

	virtual void init();

private:
	int m_value;


};

child::child()
{
	cout << "child::child\n";
	m_value = 1818;

	cout << "m_flag = " << m_flag << "\n";
	cout << "m_value = " << m_value << "\n";
}
void child::init()
{
	cout << "child::init\n";
	m_data = 3838;
}

#if 0
#endif 

int main()
{
	parent a;
	child b;

	b.init();

}




