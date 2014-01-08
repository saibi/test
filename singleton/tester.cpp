#include <iostream>

using namespace std;

template <typename T> class MySingleton
{
public:
	MySingleton() {}
	virtual ~MySingleton() {}

	static T * GetSingleton()
	{
		if ( NULL == _Singleton ) {
			_Singleton = new T;
		}
		return ( _Singleton );
	}

	static void Release()
	{
		delete _Singleton;
		_Singleton = NULL;
	}

private:
	static T * _Singleton;
};

template <typename T> T* MySingleton<T>::_Singleton = NULL;

class MyObject : public MySingleton<MyObject>
{
public:
	MyObject() : _nValue(10) {}

	void SetValue(int Value) { _nValue = Value; }
	int GetValue() { return _nValue; }

private:
	int _nValue;
};

int main()
{
	MyObject *MyObj1 = MyObject::GetSingleton();

	cout << MyObj1->GetValue() << endl;

	MyObject *MyObj2 = MyObject::GetSingleton();
	MyObj2->SetValue(20);

	cout << MyObj1->GetValue() << endl;
	cout << MyObj2->GetValue() << endl;



	return 0;
}
