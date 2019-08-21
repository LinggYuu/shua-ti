#include<iostream>
using namespace std;
int main()
{
	int apple[10];
	int h,i,n=0;
	for (i = 0; i < 10; i++)
		cin >> apple[i];
	cin >> h;
	for (i = 0; i < 10; i++)
		if (h + 30 >= apple[i])
			n++;
	cout << n;
	
	return 0;
}