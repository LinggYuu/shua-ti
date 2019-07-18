//#include<iostream>
//#include<string>
//using namespace std;
//
//int main()
//{
//	
//	string a;
//	int sum = 0;
//	cin >> a;
//	int i = 0,n=1;
//	while ((a[i] == '-') || (a[i] <= '9')&&(a[i] >= '0'))
//	{	
//		
//		if (a[i] == '-')
//			i++;
//		else 
//		{
//			sum += (a[i] - 48) * n;//n变化与 i的变化无规律时再设一个变量
//			n++;
//			i++;
//		}
//		if (n == 10)
//			break;
//	}
//	sum %= 11;
//	if (sum == 10)
//	{
//		if (a[12] == 'X')
//			cout << "Right";
//		else
//		{
//			for (i = 0; i < 12; i++)
//				cout << a[i];
//			cout << 'X';
//		}
//	}
//	else
//	{
//		if (sum == (a[12] - 48))
//			cout << "Right";
//		else
//		{
//			for (i = 0; i < 12; i++)
//				cout << a[i];
//			cout << sum;
//		}
//	}
//
//	return 0;
//}






/*char a[14];
cin >> a;
int sum=0,i;
sum += a[0] - 48;
for (i = 2; i < 11; i++)
{
	if (i < 5)
	{
		a[i] = (a[i]-48) * i;
		sum += a[i];
	}
	else if (a[i] == '-')
		continue;
	else
	{
		a[i] = (a[i]-48) * (i - 1);
		sum += a[i];
	}
}
sum %= 11;
if (sum == 10)
{
	if (a[12] == 'X')
		cout << "Right";
	else
	{
		for (i = 0; i < 13; i++)
			cout << a[i];
		cout << 'X';
	}
}
else
{
	if (sum == (a[12] - 48))
		cout << "Right";
	else
	{
		cout << a;
	}
}
*/