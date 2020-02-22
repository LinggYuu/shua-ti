#include<iostream>
using namespace std;

const int N=10;
int n;
int st[N];
int used[N];

void dfs(int u)
{
    if(u>n)
    {
        for(int i=1;i<=n;i++)
            cout<<st[i];
        cout<<endl;
    }

    for(int i=1;i<=n;i++)
    {
        if(!used[i])
        {
            st[u]=i;
            used[i]=true;
            dfs(u+1);
            st[u]=0;
            used[i]=false;
        }
    }


}