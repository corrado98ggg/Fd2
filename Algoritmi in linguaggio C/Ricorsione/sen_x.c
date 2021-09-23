#define _USE_MATH_DEFINES
#include <cfloat>
#include <math.h>

double senRec(double x, int i, int n) {

	if (n > i) {
		return 0;
	}

	double ret = ((pow(-1, n)) / tgamma(2 * n + 1 + 1)) * pow(x, 2 * n + 1);

	return ret + senRec(x, i, n + 1);
}

double sen(double x, int i) {

	if (i < 0) {
		return DBL_MIN;
	}

	return senRec(x, i, 0);
}

int main(void) {
	double c = sen(M_PI / 2, 2);
}