//p1020
//Dilworth定理。。。什么玩意
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
const  int N=100010;
int m[N];    //missile
int dp[N];
int q[N];//当前长度子序列末尾数的最小或最大值
int g[N];
int n,k;
int main()
{
    while(scanf("%d",&m[++n])==1);
    n--;
    //Ctrl + Z再按回车
    // for(int i=1;i<=n;i++)
    //     cout<<m[i]<<endl;
    
    int len=0;
    q[1]=2e9;
    for(int i=1;i<=n;i++)
    {
        int l=0,r=len;//当前有的子序列长度
        while(l<r)//找大于ai的最小值
        {
            //当前长度子序列末尾数的最大值
            int g[N];
            int mid=l+r+1 >> 1;
            if(q[mid]>=m[i])
                l=mid;
            else
                r=mid-1;
        }
        len=max(len,r+1);
        q[r+1]=m[i]; 
        //前面每种上 升子序列结尾值最大是多少
    }
    cout<<len<<endl;
    len=0;
    memset(q,0,sizeof q);
    q[0]=-2e9;
    for(int i=1;i<=n;i++)
    {
        int l=0,r=len;//当前有的子序列长度
        while(l<r)//找大于ai的最小值
        {
            int mid=l+r+1 >> 1;
            if(q[mid]<m[i])
                l=mid;
            else
                r=mid-1;
        }
        len=max(len,r+1);
        q[r+1]=m[i];
    }
    cout<<len;














    // for(int i=1;i<=n;i++)//
    // {
    //     dp[i]=1;
    //     for(int j=1;j<i;j++)
    //     {
    //         if(m[j]>=m[i])
    //         {
    //             int p=dp[i];
    //             dp[i]=max(dp[i],dp[j]+1);
    //         }
    //     }
    // }

    // int mn=0;
    // for(int i=1;i<=n;i++) mn=max(mn,dp[i]);
    // cout<<mn<<endl;
    // for(int i=1;i<=n;i++)
    // {
    //     dp[i]=1;
    //     for(int j=1;j<i;j++)
    //     {
    //         if(m[j]<m[i])
    //         {
    //             dp[i]=max(dp[i],dp[j]+1);
    //         }
    //     }
    // }
    // mn=0;
    // for(int i=1;i<=n;i++) mn=max(mn,dp[i]);
    // cout<<mn;






    system("pause");
    return 0;
}
