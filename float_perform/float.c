#include <math.h>
#include <stdio.h>

#define CONST_PI_MINUTE (M_PI)

/// generate lens adaptor r/a data 
/// \param width cannot be 0.0
/// \param height
/// \param r (out)
/// \param a (out)
/// \param count
void gen_lens_adaptor_data(float width, float height, float *r, float *a, int count)
{
	float target_theta, inflection_theta, theta_add;
	float pi_m_inflection_theta, pi_p_inflection_theta, twopi_m_inflection_theta;
	int i;

	if ( width == 0.0 ) {
		printf("ASSERT width != 0.0\n");
		return;
	}

	height /= 2.0;
	width /= 2.0;

	theta_add = (2 * CONST_PI_MINUTE) / count;
	inflection_theta = acos(height/width);
	pi_m_inflection_theta = CONST_PI_MINUTE - inflection_theta;
	pi_p_inflection_theta = CONST_PI_MINUTE + inflection_theta;
	twopi_m_inflection_theta = 2 * CONST_PI_MINUTE - inflection_theta;

	for (i = 0, target_theta = 0.0; i < count ; i++, target_theta += theta_add) {
		a[i] = target_theta;
		if ( (target_theta > inflection_theta && target_theta < pi_m_inflection_theta) || (target_theta > pi_p_inflection_theta  && target_theta < twopi_m_inflection_theta)) {
			r[i] = width;
		} else {
			r[i] = height/cos(target_theta);
			if (r[i] < 0.0 ) {
				r[i] *= -1.0;
			}
		}
	}
}

double calc(double a, double b)
{
	return a * b * 100.0 / 13.4;
}

double sum(int cnt)
{
	int i;
	double ret, sum = 0.0;

	for ( i = 0 ; i < cnt; ++i)
	{
		ret = sqrt(pow(calc(i, i * 17.1818), 3));
		sum += ret;
	}

	return sum;
}



#define MAX 5000

int main(void)
{

	int i;

	float r_list[MAX];
	float a_list[MAX];

	printf("float test\n");

	for ( i = 0 ; i < MAX; ++i)
		gen_lens_adaptor_data( 13.13 + i/511.18, 17.1818 + i/1818.18, r_list, a_list, MAX);

	for ( i = 0 ; i < MAX; ++i)
	{
		//printf("%d %f %f\n", i, r_list[i], a_list[i]);
	}

	return 0;
}

