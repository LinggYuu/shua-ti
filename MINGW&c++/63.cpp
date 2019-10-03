// p1164
#include<iostream>
#include<algorithm>
using namespace std;

const int M=10010,N=110;

int a[N];
int dp[N][M];
int m,n;

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            if(a[i]==j)
                dp[i][j]=dp[i-1][j]+1;
            else if(a[i]<j)
                dp[i][j]=dp[i-1][j]+dp[i-1][j-a[i]];
            else
                dp[i][j]=dp[i-1][j];
            

        }
    cout<<dp[n][m]<<endl;
    system("pause");
    return 0;
}

// dp[i][j]前i件，总价格为j的集合的数量
//吃这道菜的方案总数与不吃这道菜的方案总数之和