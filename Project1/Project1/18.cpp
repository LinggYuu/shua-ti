//#include<iostream>
//using namespace std;
//
//
//int main()
//{
//	int n, s;
//	int a, b;
//	int x, y;
//	int i,j,minp;
//	cin >> n>>s;
//	cin >> a >> b;
//	int st[5000];
//	for (i = 0; i < n; i++)
//	{
//		cin >> x >> y;
//		if (x <= (a + b))
//		{
//			st[i] = y;
//		}
//		else
//		{
//			i--; n--;
//		}
//	}
//
//	for (i = 0; i < n; i++)
//	{		
//		minp = i;
//		for (j = i + 1; j < n; j++)
//			if (st[j] < st[minp])
//				minp = j;
//		x = st[i];
//		st[i] = st[minp];
//		st[minp] = x;
//	}	
//	a = 0;
//	for (i = 0; i < n; i++)
//	{
//		s -= st[i];
//		if(s>=0)
//			a++;
//	}
//	cout << a;
//}