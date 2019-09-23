// p1048
#include<iostream>
#include<algorithm>
using namespace std;

int t[101];
int w[101];
int dp[101][1010];

int main()
{
    int T,M;
    cin>>T>>M;
    for(int i=1;i<=M;i++)
        cin>>t[i]>>w[i];
    
    for(int i=1;i<=M;i++)
        for(int j=0;j<=T;j++)
        {
            dp[i][j]=dp[i-1][j];
            if(j-t[i]>=0)
            {
                dp[i][j]=max(dp[i-1][j],(dp[i-1][j-t[i]]+w[i]));
            }

        }

    cout<<dp[M][T];


    system("pause");
    return 0;
}