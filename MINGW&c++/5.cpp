#include<iostream>
using namespace std;
int main() 
{
	int a[3][2];
	int n[3];
	int num, i, j,min;
	cin >> num;
	for (i = 0; i < 3; i++)
		for (j = 0; j < 2; j++)
			cin >> a[i][j];
	for (i = 0; i < 3; i++)
	{
		n[i] = num / a[i][0];
		if (num%a[i][0] != 0)
			n[i]++;
	}
	min = n[0]*a[0][1];
	for (i = 0; i < 3; i++)
	{
		n[i] = n[i] * a[i][1];
		if (n[i] < min)
			min = n[i];
	}
	cout << min;

	return 0;
}