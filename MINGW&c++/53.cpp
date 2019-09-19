// p1216
#include<iostream>
#include<algorithm>
using namespace std;

int R;
int a[1100][1100];
int dp[1100][1100];



int main()
{
    int i,j,r;
    cin>>R;
    r=1;
    for(i=R-1;i>=0;i--)
    {
        for(j=0;j<r;j++)
        {
            cin>>a[i][j];
            // cout<<i<<j<<"is"<<a[i][j];
            
        }
        r++;
    }

    // for(int i=0;i<R;i++)
    // {   
    //     cout<<endl;
    //     for(int j=0;j<R;j++)
    //         cout<<a[i][j]<<" ";
    // }
    for(int i=0;i<R;i++)
        dp[0][i]=a[0][i];
    for(int i=1;i<R;i++)
    {
        for(int j=0;j<R;j++)
        {
            dp[i][j]=max(dp[i-1][j],dp[i-1][j+1])+a[i][j];
        }
    }
    cout<<dp[R-1][0];


    system("pause");
    return 0;
}