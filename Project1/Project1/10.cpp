//#include<iostream>
//using namespace std;
//int main()
//{
//	int  L, M,i,j,num=0;
//	cin >> L >> M;
//	int a[10001][2];
//	for (i = 0; i < M; i++)
//		for (j = 0; j < 2; j++)
//			cin >> a[i][j];
//
//
//	for(i=0;i<M;i++)
//		for (j = 0; j < M; j++)
//		{
//			if (a[i][1] > a[j][0] && a[i][1] < a[j][1])
//				a[i][1] = a[j][1];
//
//			if (a[i][0] > a[j][0] && a[i][0] < a[j][1])
//				a[i][0] = a[j][0];
//		}
//	//for (i = 0; i < M; i++)
//	//	cout << a[i][0] << a[i][1] << endl;
//
//	for (i = 0; i < M; i++)
//		for (j = i+1; j < M; j++)
//		{
//			if (a[i][0] == a[j][0] || a[i][0] == a[j][1])
//				a[i][0] = 0;
//			if (a[i][1] == a[j][0] || a[i][1] == a[j][1])
//				a[i][1] = 0;
//		}
//	//for (i = 0; i < M; i++)
//	//	cout << a[i][0] << a[i][1] << endl;
//	
//	for (i = 0; i < M; i++)
//	{
//		if(a[i][1]-a[i][0]!=0)
//			num += (a[i][1] - a[i][0]+1);
//
//	}
//	num = L - num + 1;
//	cout << num;
//	return 0;
//}
