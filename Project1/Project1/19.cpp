//#include<iostream>
//using namespace std;
//
//
//
//void create(int num[])
//{
//	int i, j, k,n=0;
//	for (i = 1; i <= 9; i++)
//	{	
//		for (j = 1; j <= 9; j++)
//		{
//			if (j == i)
//				continue;
//			for (k = 1; k <= 9; k++)
//			{
//				if (k == j || k == i)
//					continue;
//				num[n] = i * 100 + j * 10 + k;
//				n++;
//			}
//		}
//	}
//}
//
//
//int main()
//{
//	int A, B, C;
//	int flag=0;
//	int num[504];	
//	cin >> A >> B >> C;
//	create(num);
//	for (int i = 0; i < 504; i++)
//	{
//		for (int j = i + 1; j < 504; j++)
//			for (int k = j + 1; k < 504; k++)
//				if ((double(num[j]) == double(num[i]) / A * B*1.0) 
//					&& (double(num[k]) == double(num[j]) / B * C*1.0)
//					)
//				{
//					if (num[i] % 10 == num[k] % 10
//						|| num[i] % 10 == num[k] % 100 / 10
//						|| num[i] % 10 == num[k] / 100
//						|| num[i] / 100 == num[k] % 10
//						|| num[i] / 100 == num[k] % 100 / 10
//						|| num[i] / 100 == num[k] / 100
//						|| num[i] % 100 / 10 == num[k] % 10
//						|| num[i] % 100 / 10 == num[k] % 100 / 10
//						|| num[i] % 100 / 10 == num[k] / 100
//						|| num[i] % 10 == num[j] % 10
//						|| num[i] % 10 == num[j] % 100 / 10
//						|| num[i] % 10 == num[j] / 100
//						|| num[i] / 100 == num[j] % 10
//						|| num[i] / 100 == num[j] % 100 / 10
//						|| num[i] / 100 == num[j] / 100
//						|| num[i] % 100 / 10 == num[j] % 10
//						|| num[i] % 100 / 10 == num[j] % 100 / 10
//						|| num[i] % 100 / 10 == num[j] / 100
//						|| num[k] % 10 == num[j] % 10
//						|| num[k] % 10 == num[j] % 100 / 10
//						|| num[k] % 10 == num[j] / 100
//						|| num[k] / 100 == num[j] % 10
//						|| num[k] / 100 == num[j] % 100 / 10
//						|| num[k] / 100 == num[j] / 100
//						|| num[k] % 100 / 10 == num[j] % 10
//						|| num[k] % 100 / 10 == num[j] % 100 / 10
//						|| num[k] % 100 / 10 == num[j] / 100)
//						continue;
//					cout << num[i] << " " << num[j] << " " << num[k] << endl;
//					flag = 1;
//
//				}
//
//
//
//
//	}
//	if (flag == 0)
//		cout << "No!!!" << endl;
//
//	return 0;
//}