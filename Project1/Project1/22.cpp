#include<iostream>
using namespace std;
int main()
{
	int n[10];
	int num,i=0,sum=0,c=1;
	cin >> num;
	while (num != 0)
	{
		n[i] = num % 10;
		num /= 10;
		i++;
	}
	for (int j = i-1; j >=0; j--)
	{
		sum += n[j] * c;
		c *= 10;
	}
	
	cout << sum;
	return 0;
}