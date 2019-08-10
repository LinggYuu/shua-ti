#include<iostream>
using namespace std;

//int w(int a, int b, int c)
//{
//	int flag = 1;
//	if (a <= 0 || b <= 0 || c <= 0)
//	{
//		flag = 0;
//		return 1;
//	}
//	if (a > 20 || b > 20 || c > 20)
//	{
//		flag = 0;
//		return w(20, 20, 20);
//	}
//	if (a < b&&b < c)
//	{
//		flag = 0;
//		return w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
//	}	
//	if (flag == 1)
//		return w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
//	return 1;
//}

int zw(int a,int b,int c)
{
	int s = 1;
	if (a <= 0 || b <= 0 || c <= 0)
		return  1;
	else
		for (int i = 0; i < a; i++)
			s *= 2;
	return s;
}

int main()
{
	int a=1,b=1,c=1,i=0;
	int n[10000][4];
	for (i = 0; i<10000; i++)
	{
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1)
			break;
		n[i][0] = a;
		n[i][1] = b;
		n[i][2] = c;
		n[i][3] = zw(a, b, c);
	}
	for (int j = 0; j < i; j++)
		cout << "w(" << n[j][0]<<", "<<n[j][1]<<", " << n[j][2]<<") = " << n[j][3] << endl;
	return 0;

}