#include<iostream>
#include<cstdio>
using namespace std;
int main() 
{
	float a, b;
	int num;//����
	cin >> a >> b;
	a = a + b * 0.1;
	num = a / 1.9;
	cout << num;
	return 0;
}