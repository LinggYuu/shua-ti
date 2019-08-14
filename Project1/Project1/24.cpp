#include<iostream>
#include<queue>
using namespace std;

int main()
{
	int M, N = 100, n[1000];
	queue<int>q;
	int i, j;
	for (i = 0; i < N; i++)
		cin >> n[i];
	q.push(1);

	for (i = 0; i < N; i++)
	{

		q.pop();
	}


	return 0;
}