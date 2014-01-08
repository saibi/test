#include <iostream>

using namespace std;


template <typename T, int VAL> T AddValue(T const & CurValue)
{
	return CurValue + VAL;
}


const int EVENT_ADD_HP_VALUE = 50;
const int EVENT_ADD_EXP_VALUE = 30;
const int EVENT_ADD_MONEY_VALUE = 10000;

int main()
{
	int Char_HP = 250;
	cout << Char_HP << " --> " << AddValue<int, EVENT_ADD_HP_VALUE>(Char_HP) << endl;


	float Char_EXP = 378.89f;
	cout << Char_EXP << " --> " << AddValue<float, EVENT_ADD_EXP_VALUE>(Char_EXP) << endl;

	long Char_Money = 34567890;
	cout << Char_Money << " --> " << AddValue<long, EVENT_ADD_MONEY_VALUE>(Char_Money) << endl;

	return 0;
}

