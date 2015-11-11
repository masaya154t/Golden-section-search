/*********************************************/
/*   Golden-search-solution                  */
/*      coded by masaya furuta               */
/*********************************************/
#include <iostream>
#include "Golden-serch.h"

//�֐��l�̒�`//
double snx(double);
//���������@//
double gold(double, double, double, double *, int *, int, double(*)(double));

int main()
{
	double a, b, eps, val, x;
	int ind, max;

	a = -2.0;
	b = -1.0;
	eps = 1.0e-10;
	max = 100;

	x = gold(a, b, eps, &val, &ind, max, snx);

	printf("x %f val %f ind %d\n", x, val, ind);

	return 0;
}

/****************/
/* �֐��l�̌v�Z */
/****************/
double snx(double x)
{
	double f;

	f = x * x * x * x + 3.0 * x * x * x + 2.0 * x * x + 1.0;

	return f;
}


