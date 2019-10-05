// p1064
#include<iostream>
#include<algorithm>
using namespace std;

const int N=32100,M=65;
int p[M],w[M],wp[M],f[M];
int p1[M],w1[M],wp1[M],f1[M];
int dp[M][N];
int n,m;
int st[M];
int main()
{   
    cin>>n>>m;//m个数,n钱数
    for(int i=1;i<=m;i++)
    {
        cin>>p[i]>>w[i]>>f[i];
        wp[i]=p[i]*w[i];
        st[f[i]]=1;
    }
    for(int i=1;i<=m;i++)
    {
        if(f[i])
        {
            p1[i]=p[i]+p[f[i]];
            wp1[i]=wp[i]+wp[f[i]];
            w1[i]=w[f[i]]+w[i];
            continue;
        }
        w1[i]=w[i];
        p1[i]=p[i];
        wp1[i]=wp[i];
    }
    for(int i=1;i<=m;i++)
    {
        cout<<p1[i]<<','<<w1[i]<<','<<wp1[i]<<','<<f[i]<<','<<st[i]<<endl;
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(f[i]==0)//不是附件
            {
                if(st[i]==1)//是主件meimai
                {              
                    dp[i][j]=dp[i-1][j];
                    if(p1[i]<=j)
                    {
                        dp[i][j]=max(dp[i-1][j],dp[i-1][j-p1[i]]+wp1[i]);
                        if(dp[i][j]==dp[i-1][j-p1[i]]+wp1[i])
                        {
                        st[i]=0;//maile
                        }
                    }
                }
                else if(st[i]==0)//maile
                {
                    dp[i][j]=dp[i-1][j];
                
                }
                else//bushizhujian
                {
                    dp[i][j]=dp[i-1][j];
                    if(p[i]<=j)
                    {
                        dp[i][j]=max(dp[i-1][j],dp[i-1][j-p[i]]+wp[i]);
                    } 
                }
            }
            else if(f[i])//fujian
            {
                if(st[f[i]]==0)//zhujianyimai
                {
                    dp[i][j]=dp[i-1][j];
                    if(p[i]<=j)
                    {
                        dp[i][j]=max(dp[i-1][j],dp[i-1][j-p[i]]+wp[i]);
                    }
                }
                else if(st[f[i]]==1)//zhujianmeimai
                {
                    dp[i][j]=dp[i-1][j];
                    if(p1[i]<=j)
                    {
                        dp[i][j]=max(dp[i-1][j],dp[i-1][j-p1[i]]+wp1[i]);
                        if(dp[i][j]==dp[i-1][j-p1[i]]+wp1[i])
                        {
                            st[f[i]]=0;
                        }
                    }
                }
            }
        }
    }
    cout<<dp[m][n]<<endl;
    system("pause");
    return 0;

}
// dp[i][j]

// if(st[i]==1)//zhujian
// {

// }