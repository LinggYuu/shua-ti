//p1002
#include<iostream>
using namespace std;
const int N=40;
long long dp[N][N];
long long a[N][N];
int dx[9]={0,-1,1,-1,1,-2,-2,2,2};
int dy[9]={0,-2,-2,2,2,-1,1,-1,1};
int n,m,mx,my;

int main()
{
    cin>>n>>m>>mx>>my;
    n++;m++;mx++;my++;
    for(int i=0;i<=8;i++)
       { dp[mx+dx[i]][my+dy[i]]=-1;
        cout<<mx+dx[i]<<","<<my+dy[i]<<endl;
       }
    // dp[0][1]=1;
    // dp[1][0]=1;

    dp[0][1]=1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {   
            a[i][j]=dp[i][j-1];
            if(dp[i][j]==-1)
                {dp[i][j]=0;
                    continue;
                    }
            else
            {
                if(i==1&&j>1)
                    dp[i][j]=dp[i][j-1];
                else if(i>1&&j==1)
                    dp[i][j]=dp[i-1][j];
                else 
                    dp[i][j]=dp[i][j-1]+dp[i-1][j];
            }
        }
        //     for(int i=1;i<=n;i++)
        // for(int j=1;j<=m;j++)
        //     cout<<a[i][j];
    cout<<dp[n][m];

    system("pause");
    return 0;


}
