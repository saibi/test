#include <iostream>

int main()
{
	using namespace std;

	float sensor_value;
	
	sensor_value = 1.345;

	if ( sensor_value == 1.345 ) {
		cout << "Sensor OK" << endl;
	} else {
		cout << "Sensor Error" << endl;
	}

	return 0;
}
