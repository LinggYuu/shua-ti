#include<iostream>
using namespace std;

const int N=20;
int st[N];
int n;

void dfs(int u)
{
    if(u>n)
    {
        for(int i=1;i<=n;i++)
        {
            if(st[i]!=0)
                cout<<st[i]<<' ';
        }
        cout<<endl;
        return;
    }
    st[u]=u;
    dfs(u+1);
    st[u]=0;

    dfs(u+1);
    st[u]=0;
}


int main()
{
    cin>>n;
    dfs(1);

    system("pause");
    return 0;
}