// p1049
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=35,V=20010;
int  n,v[N];
int vv;
int dp[N*V];//前i个物品体积小于N*V的集合的最大体积

int main()
{
    cin>>vv;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>v[i];

    for(int i=1;i<=n;i++)
    {
        for(int j=vv;j>=v[i];j--)
        {
            dp[j]=max(dp[j],dp[j-v[i]]+v[i]);
        }
    }
    cout<<(dp[vv]);



    system("pause");
    return 0;
}