#include<iostream>
using namespace  std;
int main() 
{	
	
	int num[9 * 8 * 7];
	int b, s, g,i=0,j,k;
	for (b = 1; b <= 9; b++)
		for (s = 1; s <= 9; s++)
		{
			if (s == b)
				continue;
			for (g = 1; g <= 9; g++)
			{
				if (g == s||g == b)
					continue;
				num[i] = b * 100 + s * 10 + g;
				i++;
			}
		}
	for (i = 0; i < 504; i++)
		for (j = 0; j < 504; j++)
		{
			if (num[i] % 10 == num[j] % 10
				|| num[i] % 10 == num[j] % 100 / 10
				|| num[i] % 10 == num[j] / 100
				|| num[i] / 100 == num[j] % 10
				|| num[i] / 100 == num[j] % 100 / 10
				|| num[i] / 100 == num[j] / 100
				|| num[i] % 100 / 10 == num[j] % 10
				|| num[i] % 100 / 10 == num[j] % 100 / 10
				|| num[i] % 100 / 10 == num[j] / 100)
				continue;

			for (k = 0; k < 504; k++)
			{
				if (num[i] % 10 == num[k] % 10
					|| num[i] % 10 == num[k] % 100 / 10
					|| num[i] % 10 == num[k] / 100
					|| num[i] / 100 == num[k] % 10
					|| num[i] / 100 == num[k] % 100 / 10
					|| num[i] / 100 == num[k] / 100
					|| num[i] % 100 / 10 == num[k] % 10
					|| num[i] % 100 / 10 == num[k] % 100 / 10
					|| num[i] % 100 / 10 == num[k] / 100
					|| num[k] % 10 == num[j] % 10
					|| num[k] % 10 == num[j] % 100 / 10
					|| num[k] % 10 == num[j] / 100
					|| num[k] / 100 == num[j] % 10
					|| num[k] / 100 == num[j] % 100 / 10
					|| num[k] / 100 == num[j] / 100
					|| num[k] % 100 / 10 == num[j] % 10
					|| num[k] % 100 / 10 == num[j] % 100 / 10
					|| num[k] % 100 / 10 == num[j] / 100)
						continue;
				if (num[i] == num[j] / 2
					&& num[i] == num[k] / 3
					&& num[j] % num[i] == 0
					&& num[k] % num[i] == 0
					)

					cout << num[i] <<" "<< num[j]<<" " << num[k] << endl;

			}
		}
	
	return 0;
}




�ã�
a[0] = i;//�����һ���������İ�ʮ��λ��
a[1] = j;
a[2] = k;
a[3] = r;
a[4] = t;
a[5] = y;
a[6] = u;
a[7] = o;
a[8] = p;
v = 0;
for (m = 0; m <= 8; m++)//һ����һ�����Ƚϣ�������ͬv=1
for (n = m + 1; n <= 8; n++)
{
	if (a[m] == a[n])
		v = 1;
����: makimakima