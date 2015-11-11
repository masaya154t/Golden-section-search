/*********************************************/
/*   Golden-search-solution                  */
/*      coded by masaya furuta               */
/*********************************************/
#include <iostream>
#include "Golden-serch.h"

using namespace std;

//関数値の定義//
double snx(double α);

//リンク旅行時間//
double link_TimeA(double);
double link_TimeB(double);
double link_TimeC(double);
double link_TimeD(double);
double link_TimeE(double);

//経路旅行時間//
double pass_Time_a(double, double);
double pass_Time_b(double, double);
double pass_Time_c(double, double, double);


int main()
{
	double val,α;
	int ind;

	//リンク交通量//
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

	//経路旅行時間//
	double time_a = pass_Time_a(xa, xb);
	double time_b = pass_Time_b(xc, xd);
	double time_c = pass_Time_c(xa, xd, xe);

	//ynの決定(All or nothing)配分//
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


	α = gold(&val, &ind, snx);

	printf("α %f val %f ind %d\n", α, val, ind);

	return 0;
}

//リンクAの旅行時間//
double link_TimeA(double xa){
	return 10 + 10 * xa;
}
//リンクBの旅行時間//
double link_TimeB(double xb){
	return 60 + xb;
}
//リンクCの旅行時間//
double link_TimeC(double xc){
	return 60 + xc;
}
//リンクDの旅行時間//
double link_TimeD(double xd){
	return 10 + 10 * xd;
}
//リンクEの旅行時間//
double link_TimeE(double xe){
	return 10 + xe;
}

//経路a旅行時間//
double pass_Time_a(double xa, double xb){
	return link_TimeA(xa) + link_TimeB(xb);
}
//経路b旅行時間//
double pass_Time_b(double xc, double xd){
	return link_TimeC(xc) + link_TimeD(xd);
}
//経路c旅行時間//
double pass_Time_c(double xa, double xd, double xe){
	return link_TimeA(xa) + link_TimeD(xd) + link_TimeE(xe);
}

/******************/
/* 目的間数の計算 */
/******************/
double snx(double α)
{
	double z;

	z = (α - 1)*(α - 1);

	return z;
}


