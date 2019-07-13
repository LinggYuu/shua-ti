//#include<iostream>
//using namespace std;
//
//int main() 
//{ 
//	int a[7][2];
//	int time[7];//每天的时间
//	int i, j, k, maxp;//一些参数变量
//	for (i = 0; i < 7; i++)
//		for (j = 0; j < 2; j++)
//			cin >> a[i][j];
//	
//	for (k = 0; k < 7; k++)
//		time[k] = a[k][0] + a[k][1];
//	//cout << time[3];
//
//	maxp = 0;
//	for (i = 1; i < 7; i++) 
//	{
//		if (time[i] > time[maxp])
//			maxp = i;
//	}
//
//	cout << maxp+1;
//	return 0; 
//}