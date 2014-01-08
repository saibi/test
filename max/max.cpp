#include <iostream>

using namespace std;

// v3
template <typename T1, typename T2> const T1& Max(const T1& a, const T2& b)
{
	return a > b ? a : b;
}

// v2
#if 0
template <typename T> const T& Max(const T& a, const T& b)
{
	return a > b ? a : b;
}
#endif 

// v1
#if 0
template <typename T> T Max(T a, T b)
{
	return a > b ? a : b;
}
#endif 


int main()
{
	int Char1_HP = 300;
	int Char2_HP = 400;
	int MaxCharHP = Max(Char1_HP, Char2_HP);

	cout << "Max HP " << MaxCharHP << endl;

	float Char1_Exp = 250.0f;
	float Char2_Exp = 250.57f;
	float MaxCharExp = Max(Char1_Exp, Char2_Exp);

	cout << "Max Exp " << MaxCharExp << endl;

	int Char1_MP = 300;
	double Char1_SP = 400.25;
	double MaxValue = Max(Char1_MP, Char1_SP);

	cout << "Max " << MaxValue << endl;

	return 0;
}




