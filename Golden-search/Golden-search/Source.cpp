/*********************************************/
/*   Golden-search-solution                  */
/*      coded by masaya furuta               */
/*********************************************/
#include <iostream>
#include "Golden-serch.h"

using namespace std;

//�֐��l�̒�`//
double snx(double ��);

//�����N���s����//
double link_TimeA(double);
double link_TimeB(double);
double link_TimeC(double);
double link_TimeD(double);
double link_TimeE(double);

//�o�H���s����//
double pass_Time_a(double, double);
double pass_Time_b(double, double);
double pass_Time_c(double, double, double);


int main()
{
	double val,��;
	int ind;

	//�����N��ʗ�//
	double xa = 6000;
	double xb = 6000;
	double xc = 0;
	double xd = 0;
	double xe = 0;

	double ya = 0;
	double yb = 0;
	double yc = 0;
	double yd = 0;
	double ye = 0;

	double xa_1 = 0;
	double xb_1 = 0;
	double xc_1 = 0;
	double xd_1 = 0;
	double xe_1 = 0;

	//�o�H���s����//
	double time_a = pass_Time_a(xa, xb);
	double time_b = pass_Time_b(xc, xd);
	double time_c = pass_Time_c(xa, xd, xe);

	//yn�̌���(All or nothing)�z��//
	if (time_a > time_b){
		if (time_b > time_c){
			ya = 6000; yb = 0; yc = 0; yd = 6000; ye = 6000;
		}
		else{
			ya = 0; yb = 0; yc = 6000; yd = 6000; ye = 0;
		}
	}
	else{
		if (time_a > time_c){
			ya = 6000; yb = 0; yc = 0; yd = 6000; ye = 6000;
		}
		else{
			ya = 6000; yb = 6000; yc = 0; yd = 0; ye = 0;
		}
	}


	�� = gold(&val, &ind, snx);

	printf("�� %f val %f ind %d\n", ��, val, ind);

	return 0;
}

//�����NA�̗��s����//
double link_TimeA(double xa){
	return 10 + 10 * xa;
}
//�����NB�̗��s����//
double link_TimeB(double xb){
	return 60 + xb;
}
//�����NC�̗��s����//
double link_TimeC(double xc){
	return 60 + xc;
}
//�����ND�̗��s����//
double link_TimeD(double xd){
	return 10 + 10 * xd;
}
//�����NE�̗��s����//
double link_TimeE(double xe){
	return 10 + xe;
}

//�o�Ha���s����//
double pass_Time_a(double xa, double xb){
	return link_TimeA(xa) + link_TimeB(xb);
}
//�o�Hb���s����//
double pass_Time_b(double xc, double xd){
	return link_TimeC(xc) + link_TimeD(xd);
}
//�o�Hc���s����//
double pass_Time_c(double xa, double xd, double xe){
	return link_TimeA(xa) + link_TimeD(xd) + link_TimeE(xe);
}

/******************/
/* �ړI�Ԑ��̌v�Z */
/******************/
double snx(double ��)
{
	double z;

	z = (�� - 1)*(�� - 1);

	return z;
}


