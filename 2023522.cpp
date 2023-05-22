//槽轮的角加速度α2和角加速度W2

#include <iostream>
#include <math.h>

int main()
{
	using namespace std;
	const int number = 9;
	const int degree = 180 / 3.1415926;
	int lmt_1 = 0.5;
	int lmt_2 = 0.25;

	int a[number]{ 0,30,45,60,90,-30,-45,-60,-90 };
	double w1 = 6.18;
	double w2[number]{0};
	double w2_w1[number]{ 0 };
	double a2_w1[number]{ 0 };
	double a2[number]{ 0 };
	for (int i = 0; i < number; i++)
	{
		//w2_w1[i] = lmt_1*((cos(a[i])-lmt_1)/(1-2*lmt_1*cos(a[i])+lmt_2));//λ（cosα-λ）/（1-2λ*cosα+λ2）
		//w2[i] = w2_w1[i] * w1;
		w2_w1[i] = (2*cos(a[i]*degree)-1)/(5-4*cos(a[i]*degree));
		w2[i] = w2_w1[i] * w1;
		a2_w1[i] = ((-3/8.0)*sin(a[i]*degree))/((5/4.0)-cos(a[i]*degree));
		a2[i] = a2_w1[i] * w1;
	}
	cout << "α\t w2/w1 \t w2 \t a2/w1 \t a2" << endl;
	for (int i = 0; i < number; i++)
	{
		cout <<a[i]<<"   "<<w2_w1[i]<<"   "<<w2[i]<<"   "<<a2_w1[i]<<"    "<<a2[i]<<endl;
	}
	return 0;
}