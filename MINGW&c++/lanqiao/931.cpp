#include<iostream>
using namespace std;

const int M=26;

int st[M];
bool used[M];
int m,n;
void dfs(int u)
{
    if(u>m)
    {
        for(int i=1;i<=m;i++)
        {
            cout<<st[i]<<' ';
        }
        cout<<endl;
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(!used[i]&&st[u-1]<i)
        {
            st[u]=i;
            used[i]=true;
            dfs(u+1);
            st[i]=0;
            used[i]=false;
        }
    }
}

int main()
{
    cin>>n>>m;
    dfs(1);
    system("pause");
    return 0;
}