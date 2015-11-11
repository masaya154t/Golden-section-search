#include <iostream>
#define  EPS  1e-3//��������p
using namespace std;

//������̒l
static const double GRATIO = 1.6180339887498948482045868343656;

//�ȒP�ȉ��ɓʂȊ֐�f(x) = (x-1)^2�Bx=1�ōŏ��l0�B
double f(double x){
	return (x - 1.0)*(x - 1.0);
}

//���������@
// f(x)�����[lb,ub]�œʂȂ�΁A���̋ɒl��Ԃ�
// �������ɒl���g���܂킹��̂ŁAf�̌v�Z��1��݂̂ł悢
// ub: ����    ub: ���    K: ������
double goldenSectionSearch(double lb, double ub, int K){
	double x1, x2; //�����_(1:GRATIO��GRATIO:1�ɕ�������_)
	double f1, f2; //�����_�ł̒l

	//�����_���v�Z
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