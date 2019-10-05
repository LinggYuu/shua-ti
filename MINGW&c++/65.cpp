// p1616
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int T=100010,M=10010;
int n,m;
int ti[M],v[M];
int dp[10000010];

int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>ti[i]>>v[i];
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=ti[i];j<=n;j++)
        {
            dp[j]=max(dp[j],dp[j-ti[i]]+v[i]);
        }
    }
    cout<<dp[n];

    system("pause");
    return 0;

}
