// p1064
#include<iostream>
#include<algorithm>
using namespace std;

const int N=60,M=32100;
int vp[N][4];
int v[N][4];
int dp[N*M*3];
int dpp[N];
int q;
int n,m;
int cnt;
int main()
{
    cin>>m>>n;
    for(int i=1;i<=n;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        q=c;
        if(q==0)
        {
            v[i][0]=a;
            vp[i][0]=a*b;
        }
        if(q!=0)
        {
            cnt=1;
            if(vp[q][cnt]!=0)
                cnt++;
            v[q][cnt]=a+v[q][0];
            vp[q][cnt]=a*b+vp[q][0];
            if(cnt==2)
            {
                v[q][3]=v[q][2]+v[q][1]-v[q][0];
                vp[q][3]=vp[q][2]+vp[q][1]-vp[q][0];
            }
        }
    }
    // cout<<vp[5][1]<<','<<vp[5][2];

    for(int i=1;i<=n;i++)
    {
        for(int j=m;j>=0;j--)
        {
            for(int k=0;k<=3;k++)
            {
                if(v[i][k]<=j&&v[i][k]!=0)
                {
                    dp[j]=max(dp[j],dp[j-v[i][k]]+vp[i][k]);
                }

            }
        }
    }
    cout<<dp[m]<<endl;
    system("pause");
    return 0;
}