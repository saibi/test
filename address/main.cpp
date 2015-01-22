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


//class cat
//{
//public:
//	cat(int val = 0) : m_value(val)
//	{
//		cout << "cat() constructor, m_value = " << m_value << "\n";
//	}

//	~cat()
//	{
//		cout << "~cat()\n";
//	}

//	cat(const cat & r)
//	{
//		m_value = r.m_value;
//		cout << "cat()copy\n";
//	}

//	int get() const
//	{
//		return m_value;
//	}

//	void inc()
//	{
//		++m_value;
//	}

//	cat & operator++()
//	{
//		++m_value;
//		return *this;
//	}

//	cat operator++(int)
//	{
//		int prev = m_value;
//		++m_value;
//		return prev;
//	}

//	cat operator+(const cat & rhs) const
//	{
//		return (m_value + rhs.m_value);
//	}

//private:
//	int m_value;
//};

//cat operator+(int val, const cat & rhs)
//{
//	cat temp(val);
//	return temp + rhs;
//}


//class CIntArray
//{
//public:
//	CIntArray(int iMaxArray = 10) : m_iMaxArray(iMaxArray)
//	{
//		m_pData = new int[m_iMaxArray];
//	}
//	~CIntArray()
//	{
//		delete [] m_pData;
//	}

//	CIntArray(const CIntArray & rhs) : m_iMaxArray(rhs.m_iMaxArray)
//	{
//		m_pData = new int[m_iMaxArray];
//		for ( int i = 0 ; i < rhs.m_iMaxArray; ++i)
//			m_pData[i] = rhs.m_pData[i];
//	}


//	int size() const
//	{
//		return m_iMaxArray;
//	}

//	int & operator[](int i)
//	{
//		return m_pData[i];
//	}
//	int operator[](int i) const
//	{
//		return m_pData[i];
//	}

//	CIntArray & operator= (const CIntArray & rhs)
//	{
//		if ( this == &rhs )
//			return *this;

//		delete [] m_pData;
//		m_pData = new int[m_iMaxArray];
//		for ( int i = 0 ; i < rhs.m_iMaxArray; ++i)
//			m_pData[i] = rhs.m_pData[i];

//		return *this;
//	}

//private:
//	int * m_pData;
//	int m_iMaxArray;
//};


#include <string.h>

//class CMyString
//{
//public:
////	CMyString() : m_iLength(0)
////	{
////		m_pData = new char [m_iLength+1];
////		m_pData[0] = 0;
////	}
//	CMyString(const char *pData = "" ) : m_iLength(strlen(pData))
//	{
//		m_pData = new char [m_iLength+1];
//		strcpy(m_pData, pData);
//	}

//	~CMyString()
//	{
//		delete [] m_pData;
//	}

//	CMyString(const CMyString &rhs) : m_iLength(rhs.m_iLength)
//	{
//		m_pData = new char [m_iLength+1];
//		strcpy(m_pData, pData);
//	}

//	CMyString & operator=(const CMyString & rhs) // const not applicable because this can be changed
//	{
//		if ( this == &rhs )
//			return *this;

//		delete [] m_pData;

//		m_iLength = rhs.m_iLength;
//		m_pData = new char[m_iLength + 1];
//		strcpy(m_pData, rhs.m_pData);

//		return *this;
//	}

//	char & operator[](int iIndex)
//	{
//		return m_pData[iIndex];
//	}

//	char operator[](int iIndex) const
//	{
//		return m_pData[iIndex];
//	}

//	const char * GetData() const
//	{
//		return m_pData;
//	}

//	int GetLength() const
//	{
//		return m_iLength;
//	}
//private:
//	char *m_pData;
//	int m_iLength;
//};


//class Animal
//{
//public:
//	virtual void speak()
//	{
//		cout << "animal\n";
//	}

//	virtual ~Animal()
//	{
//		cout << "~Animal()\n";
//	}

//	virtual void speak2()
//	{
//		cout << "animal2\n";
//	}

//};

//class Dog : public Animal
//{
//public:

//	virtual ~Dog()
//	{
//		cout << "~Dog()\n";
//	}

//	virtual void speak2()
//	{
//		cout << "dog2\n";
//	}

//	virtual void speak()
//	{
//		cout << "dog\n";
//	}


//};


class Weapon
{
public:
	virtual void Attack() const
	{
	}
};

class Sword : public Weapon
{
public:
	void Attack() const
	{
		cout << "sword" << endl;
	}
};

class Gun : public Weapon
{
public:
	void Attack() const
	{
		cout << "gun" << endl;
	}
};

class Missle : public Weapon
{
public:
	void Attack() const
	{
		cout << "missle" << endl;
	}
};

class CRobot
{
public:
	CRobot(int iWeapon) : m_iWeapon(iWeapon)
	{

	}

	CRobot(Weapon *pWeapon) : m_pWeapon(pWeapon)
	{

	}

	void Attack() const
	{
//		switch (m_iWeapon)
//		{
//		case 1:
//			cout << "sword" << endl;
//			break;

//		case 2:
//			cout << "gun" << endl;
//			break;

//		case 3:
//			cout << "missle" << endl;
//			break;
//		}
		m_pWeapon->Attack();
	}

	void ChangeWeapon(int iWeapon)
	{
		m_iWeapon = iWeapon;
	}

private:
	int m_iWeapon;

	Weapon *m_pWeapon;
};

int main()
{
	cout << "Hello World!" << endl;

	CRobot r(1);
	r.Attack();
	r.ChangeWeapon(2);
	r.Attack();


//	Animal *p = new Dog();

//	p->speak();

//	p->speak2();

//	delete p;

//	CIntArray iArray;

//	for (int i = 0 ; i < iArray.size(); ++i)
//		iArray[i] = i;

//	CIntArray iArray2(iArray);
//	for (int i = 0 ; i < iArray2.size(); ++i)
//		cout << i << " = " << iArray2[i] << endl;



//	cat c1(10);
//	cat c2;

//	cout << c1.get() << endl;
//	c1.inc();
//	cout << c1.get() << endl;

//	c2 = c1++;
//	//c1++;
//	cout << c1.get() << endl;
//	cout << c2.get() << endl;

//	cat c3 = c1 + c2;
//	cout << c3.get() << endl;

//	cat c4 = c1 + 50;
//	cout << c4.get() << endl;

//	c3 = 20 + c1;

//	int iValue = 10;
//	int & rValue = iValue;
//	cout << "iValue" << iValue << endl;
//	cout << "&iValue" << &iValue << endl;
//	cout << "rValue" << rValue << endl;
//	cout << "&rValue" << &rValue << endl;

//	const int val = 7;

//	const int *p = &val;


//	int val2;

//	int * const p2 = &val2;

//	val2 = 2;

//	p = &val2;

//	p2 = 0;


//	printf("sum = %f\n", sum(1.0f, 2.0f));



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

