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
       {    if(mx+dx[i]>=0&&my+dy[i]>=0)
           dp[mx+dx[i]][my+dy[i]]=-1;
        cout<<mx+dx[i]<<","<<my+dy[i]<<endl;
       }
    // dp[0][1]=1;
    dp[1][0]=1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {   
            // a[i][j]=dp[i][j-1];
            if(dp[i][j]==-1)
                {dp[i][j]=0;
                    continue;
                    }
            else
            {
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
// 要考虑一下边界的问题 边界上如果有0 从该点向后都是不能取的

// for(int i=1;i<=m;i++)if(num[0][i-1]==0) num[0][i]=0;

// for(int i=1;i<=n;i++)if(num[i-1][0]==0) num[i][0]=0;
// 注意考虑边界条件，如果有马或马控点在（0，y）或（x，0）上，则之后的点（0，n）（n>=y）及(0,m)(m>=x) 可行方案数都为0！