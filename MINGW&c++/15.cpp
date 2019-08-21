#include<iostream>
using namespace std;


//�ݹ��ϵ,diguishi
//�ݹ����
//��=��return
//int f(int num)
//{	
//	int s[1001];
//	s[0] = 1;
//	s[1] = 1;
//	for (int i = 2; i <= 1000; i++)
//	{
//		if (i % 2 == 0)
//			s[i] = s[i-1]+s[i/2];
//		else
//			s[i] =s[i-1];
//
//	}
//	return s[num];
//}
int f(int num)
{
	if (num == 0 || num == 1)
		return 1;
	else if (num % 2 == 0)
		return f(num - 1) + f(num / 2);
	else if (num % 2 != 0)
		return f(num - 1);


}
int main()
{
	int number;
	int num=0;
	cin >> number;
	num=f(number);
	cout << num;
	return 0;
}	
