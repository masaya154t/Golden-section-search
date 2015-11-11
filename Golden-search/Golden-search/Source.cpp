/*********************************************/
/* 黄金分割法によるy=x^4+3x^3+2x^2+1の最小値 */
/*      coded by Y.Suganuma                  */
/*********************************************/
#include <stdio.h>

double snx(double);
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
/* 関数値の計算 */
/****************/
double snx(double x)
{
	double f;

	f = x * x * x * x + 3.0 * x * x * x + 2.0 * x * x + 1.0;

	return f;
}

/******************************************/
/* 黄金分割法(関数の最小値)               */
/*      a,b : 初期区間 a < b              */
/*      eps : 許容誤差                    */
/*      val : 間数値                      */
/*      ind : 計算状況                    */
/*              >= 0 : 正常終了(収束回数) */
/*              = -1 : 収束せず           */
/*      max : 最大試行回数                */
/*      fun : 関数値を計算する関数の名前  */
/*      return : 結果                     */
/******************************************/
#include <math.h>

double gold(double a, double b, double eps, double *val, int *ind, int max, double(*fun)(double))
{
	double f1, f2, fa, fb, tau, x = 0.0, x1, x2;
	int count;

	tau = (sqrt(5.0) - 1.0) / 2.0;
	count = 0;
	*ind = -1;
	x1 = b - tau * (b - a);
	x2 = a + tau * (b - a);
	f1 = fun(x1);
	f2 = fun(x2);

	while (count < max && *ind < 0) {
		count += 1;
		if (f2 > f1) {
			if (fabs(b - a) < eps && fabs(b - a) < eps*fabs(b)) {
				*ind = 0;
				x = x1;
				*val = f1;
			}
			else {
				b = x2;
				x2 = x1;
				x1 = a + (1.0 - tau) * (b - a);
				f2 = f1;
				f1 = fun(x1);
			}
		}
		else {
			if (fabs(b - a) < eps && fabs(b - a) < eps*fabs(b)) {
				*ind = 0;
				x = x2;
				*val = f2;
				f1 = f2;
			}
			else {
				a = x1;
				x1 = x2;
				x2 = b - (1.0 - tau) * (b - a);
				f1 = f2;
				f2 = fun(x2);
			}
		}
	}

	if (*ind == 0) {
		*ind = count;
		fa = fun(a);
		fb = fun(b);
		if (fb < fa) {
			a = b;
			fa = fb;
		}
		if (fa < f1) {
			x = a;
			*val = fa;
		}
	}

	return x;
}
