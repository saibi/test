#include <iostream>

template <typename T, int Size = 100> class Stack
{
public:
	explicit Stack(int size = 50)
	{
		m_Size = size;
		m_aData = new T[m_Size];

		Clear();
	}

	~Stack()
	{
		delete [] m_aData;
	}


	void Clear()
	{
		m_Count = 0;
	}

	int Count()
	{
		return m_Count;
	}

	bool IsEmpty()
	{
		return 0 == m_Count ? true : false;
	}

	int GetStackSize()
	{
		return m_Size;
	}

	bool push(T data)
	{
		if ( m_Count >= m_Size )
		{
			return false;
		}

		m_aData[ m_Count ] = data;
		++m_Count;

		return true;
	}

	T pop()
	{
		if ( m_Count < 1 ) 
		{
			return 0;
		}

		--m_Count;

		return m_aData[ m_Count ];
	}

private:
	T* m_aData;
	int m_Count;

	int m_Size;
};



#if 0
const int MAX_EXP_COUNT = 100;

template <typename T, int Size = MAX_EXP_COUNT> class Stack
{
public:
	Stack()
	{
		Clear();
	}

	void Clear()
	{
		m_Count = 0;
	}

	int Count()
	{
		return m_Count;
	}

	bool IsEmpty()
	{
		return 0 == m_Count ? true : false;
	}

	int GetStackSize()
	{
		return Size;
	}

	bool push(T data)
	{
		if ( m_Count >= Size )
		{
			return false;
		}

		m_aData[ m_Count ] = data;
		++m_Count;

		return true;
	}

	T pop()
	{
		if ( m_Count < 1 ) 
		{
			return 0;
		}

		--m_Count;

		return m_aData[ m_Count ];
	}

private:
	T m_aData[Size];
	int m_Count;
};

#endif 


using namespace std;

int main()
{
	//Stack <double, 5> kExpStack;
	Stack <double> kExpStack(5);

	cout << "Stack Size = " << kExpStack.GetStackSize() << endl;
	kExpStack.push(145.5f);
	kExpStack.push(183.25f);
	kExpStack.push(162.3f);


	int Count = kExpStack.Count();

	for ( int i = 0 ; i < Count; ++i ) 
	{
		cout << kExpStack.pop() << endl;
	}


	Stack <long> kStackMoney;

	cout << "Stack Size = " << kStackMoney.GetStackSize() << endl;

	kStackMoney.push(1000023);
	kStackMoney.push(1000234);
	kStackMoney.push(1000145);

	Count = kStackMoney.Count();
	for ( int i = 0 ; i < Count; ++i) {
		cout << "money - " << kStackMoney.pop() << endl;
	}

	return 0;
}

