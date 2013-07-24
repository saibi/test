#include <iostream>

using namespace std;

template <typename T> T Max(T a, T b)
{
	return a > b ? a : b;
}


int main()
{
	int Char1_HP = 300;
	int Char2_HP = 400;
	int MaxCharHP = Max(Char1_HP, Char2_HP);

	cout << "Max HP " << MaxCharHP << endl << endl;

	float Char1_Exp = 250.0f;
	float Char2_Exp = 250.57f;
	float MaxCharExp = Max(Char1_Exp, Char2_Exp);

	cout << "Max Exp " << MaxCharExp << endl << endl;

	return 0;
}




