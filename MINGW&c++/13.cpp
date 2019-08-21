#include<iostream>
#include<string>
using namespace std;
int main()
{
	string hname,dname;
	int i,sum1=1,sum2=1;
	cin >> hname >> dname;
	
	for (i = 0; hname[i] != '\0'; i++)
		sum1*=(hname[i] - 64);
	for (i = 0; dname[i] != '\0'; i++)
		sum2 *= (dname[i] - 64);
	if (sum1 % 47 == sum2 % 47)
		cout << "GO";
	else
		cout << "STAY";

	return 0;
}