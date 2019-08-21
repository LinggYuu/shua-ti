//#include<iostream>
//#include<queue>
//using namespace std;
//
//int main()
//{
//	int M, N = 100, n[1000];
//	queue<int>q;
//	int i, j;
//	for (i = 0; i < N; i++)
//		cin >> n[i];
//	q.push(1);
//
//	for (i = 0; i < N; i++)
//	{
//
//		q.pop();
//	}
//
//
//	return 0;
//}
//quicksort
#include<iostream>
using namespace std;

void swap(int &a, int &b)
{
	int t = a;
	a = b;
	b = t;
}
int  point(int s[], int l, int r)
{
	int t;
	int c = (l + r) / 2;
	if (s[l] >= s[r])
	{
		swap(l, r);
	}
	if (s[c] < s[l])
	{
		swap(c, l);
	}
	if (s[r] < s[c])
	{
		swap(r, c);
	}
	return c;
}



void quicksort(int s[], int left, int right)
{
	if (left >= right)
		return;
	int i = left, j = right;
	int k = point(s, left, right);
	swap(s[i], s[k]);
	int x = s[i];
	while (i < j)
	{
		while (i < j&&s[j] >= x)
			j--;
		if (i < j)
			s[i++] = s[j];
		while (i < j&&s[i] < x)
			i++;
		if (i < j)
			s[j--] = s[i];
	}
	s[i] = x;
	quicksort(s, left, i - 1);
	quicksort(s, i + 1, right);
}


int main()
{
	int a[100001];
	int N, i;
	cin >> N;
	for (i = 0; i < N; i++)
	{
		cin >> a[i];
	}

	// int x=point(a,0,N-1);
	// cout<<x;

	quicksort(a, 0, N - 1);

	for (i = 0; i < N; i++)
		cout << a[i] << " ";



	return 0;
}