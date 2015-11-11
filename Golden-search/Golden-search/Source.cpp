#include <iostream>
#define  EPS  1e-3//収束判定用
using namespace std;

//黄金比の値
static const double GRATIO = 1.6180339887498948482045868343656;

//簡単な下に凸な関数f(x) = (x-1)^2。x=1で最小値0。
double f(double x){
	return (x - 1.0)*(x - 1.0);
}

//黄金分割法
// f(x)が区間[lb,ub]で凸ならば、その極値を返す
// 反復時に値が使いまわせるので、fの計算が1回のみでよい
// ub: 下限    ub: 上限    K: 反復回数
double goldenSectionSearch(double lb, double ub, int K){
	double x1, x2; //内分点(1:GRATIOとGRATIO:1に分割する点)
	double f1, f2; //内分点での値

	//内分点を計算
	x1 = (ub - lb) / (GRATIO + 1.0) + lb;
	f1 = f(x1);
	x2 = (ub - lb) / GRATIO + lb;
	f2 = f(x2);

	for (int i = 0; i<K; i++){
		if (f1 < f2){
			ub = x2;
			x2 = x1; f2 = f1;
			x1 = (ub - lb) / (GRATIO + 1.0) + lb;
			f1 = f(x1);
		}
		else{
			lb = x1;
			x1 = x2; f1 = f2;
			x2 = (ub - lb) / GRATIO + lb;
			f2 = f(x2);
		}
	}

	return (lb + ub) / 2.0;
}


int main(){

	cout << goldenSectionSearch(-10.0, 10.0, 30) << endl;

	return 0;
}