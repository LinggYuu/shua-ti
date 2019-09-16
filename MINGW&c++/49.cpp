// R24000490
#include<iostream>
#include<algorithm>
using namespace std;

int N,m;
int p[30],w[30];
int dp[30][30100];


int main()
{
    cin>>N>>m;
    for(int i=0;i<m;i++)
        cin>>p[i]>>w[i];
    for(int i=1;i<=m;i++)
        for(int j=0;j<=N;j++)
        {
            dp[i][j]=dp[i-1][j];
            if(j>=p[i-1])
            dp[i][j]=max(dp[i-1][j],(dp[i-1][j-p[i-1]]+w[i-1]*p[i-1]));
        }
    cout<<dp[m][N];

    system("pause");
    return 0;
}