#include<iostream>
using namespace std;
const int N=25;
int n,m;
int st[N];
bool used[N];

void dfs(int u)
{
    if(u>m)
    {
        for(int k=1;k<=m;k++)
            cout<<st[k]<<' ';

        cout<<endl;
        return;
    }
        for(int j=u;j<=n;j++)
        {
            if(used[j]!=true&&st[u-1]<j)
            {
                st[u]=j;
                used[j]=true;
                dfs(u+1);
                st[u]=0;
                used[j]=false;
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