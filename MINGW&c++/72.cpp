//p1020
//Dilworth定理。。。什么玩意
#include<iostream>
#include<algorithm>
using namespace std;
const  int N=100010;
int m[N];    //missile
int dp[N];
int g[N];
int n,k;
int main()
{
    while(scanf("%d",&m[++n])==1);
    n--;
    //Ctrl + Z再按回车
    // for(int i=1;i<=n;i++)
    //     cout<<m[i]<<endl;
    for(int i=1;i<=n;i++)//倒序
    {
        dp[i]=1;
        for(int j=1;j<i;j++)
        {
            if(m[j]>=m[i])
            {
                int p=dp[i];
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
    }

    int mn=0;
    for(int i=1;i<=n;i++) mn=max(mn,dp[i]);
    cout<<mn<<endl;
    for(int i=1;i<=n;i++)
    {
        dp[i]=1;
        for(int j=1;j<i;j++)
        {
            if(m[j]<m[i])
            {
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
    }
    mn=0;
    for(int i=1;i<=n;i++) mn=max(mn,dp[i]);
    cout<<mn;






    system("pause");
    return 0;
}
