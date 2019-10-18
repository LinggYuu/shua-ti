// p1280
#include<iostream>
#include<algorithm>
using namespace std;

const int N=10010,K=10010;
int n,k,x=1;
int dp[K],s[K];

struct tk
{
    int p;
    int t;
} task[K];

bool cmp(tk a,tk b)
{
    return a.p>b.p;
}

int main()
{
    cin>>n>>k;
    for(int i=1;i<=k;i++)//k个任务的起始和时长
    {
        cin>>task[i].p>>task[i].t;
    }
    
    sort(task+1,task+k+1,cmp);

    for(int i=1;i<=k;i++)
    {
       s[task[i].p]++;//s[时刻]的任务数
    }
    // for(int i=1;i<=k;i++)
    // {
    //     cout<<s[task[i].p]<<endl;
    // }
    for(int i=n;i>=1;i--)//时刻
    {
        if(!s[i])
        {
            dp[i]=dp[i+1]+1;
        }
        else if(s[i])//有任务
        {
            for(int j=1;j<=s[i];j++)
            {
                if(dp[i]<dp[i+task[x].t])
                    dp[i]=dp[i+task[x].t];
                x++;
            }
        }
    }
    cout<<dp[1];
    system("pause");
    return 0;
}