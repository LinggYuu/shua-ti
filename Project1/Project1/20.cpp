//#include<iostream>
//using namespace std;
//
//int ip(int n)
//{
//	for (int i = 2; i < n; i++)
//		if (n%i == 0)
//			return 0;
//	return 1;
//}
//
//
//int main()
//{
//	int n,t=0;
//	int a[10000];
//	cin >> n;
//
//	for(int i=2;i<n;i++)
//		if (ip(i))
//		{
//			a[t] = i;
//			t++;
//		}
//	
//
//	for (int i = 0; i < t; i++)
//		for (int j = 0; j < t; j++)
//			for (int k = 0; k < t; k++)
//				if (a[i] + a[j] + a[k] == n
//					&&a[i]<=a[j]
//					&&a[j]<=a[k])
//				{
//					cout << a[i] << " " << a[j] << " " << a[k] << endl;
//					return 0;
//				}
//
//	return 0;
//}