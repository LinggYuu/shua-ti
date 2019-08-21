#include<iostream>
using namespace std;
//forѭ����Ƕ�ݹ������������
// 4 3 
// 3 7 12 19
int ans=0;
int num[20];
int s = 0;
int n = 0;
int isprime(int num)
{
	for (int i = 2; i < num; i++)
		if (num%i == 0)
		{
			return 0;//��������
		}
		return 1;//����������1
}

void fun( int n1, int n2,int k,int n)
{
	int i;
	if (n2 == k)
	{
		if (isprime(s) == 1)
			ans++;
		return;
	}
	else
		for (i = n1; i < n; i++)
		{
			s += num[i];
			fun( i+1, n2 + 1, k, n);		
			s -= num[i];
		}	

}


int main()
{
	
	int n,i,k;
	cin >> n >> k;
	for (i = 0; i < n; i++)
		cin >> num[i];
	
	fun(0,0,k,n);
	cout << ans;
	return 0;
}





	int i,j,k;
	int sum=0;
	for (i = 0; i < n; i++)
		for (j = i+1; j < n; j++)
			for (k = j+1; k < n; k++)
				cout << num[i] << "+"<<num[j]<<"+" << num[k] << endl;
					