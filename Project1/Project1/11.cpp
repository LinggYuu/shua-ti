#include<iostream>
using namespace std;
int main()
{
	int a[100];
	int i,n=0;
	int flag = 1;
	for (i = 0; i < 100; i++)
	{
		
		cin >> a[i];
		if (a[i] == 0)
			break;
		n++;
						
	}


	for (i = n-1; i>=0; i--)
	{
		cout << a[i]<<" ";
	}
	return 0;
}