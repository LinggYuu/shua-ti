
#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;


const int N=100010,M=N*2;

int n,m;
int h[N],e[M],ne[M],idx;
bool st[N];
int ans=N;

void add(int a,int b)
{
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx++;
}



// void dfs(int u)
// {
//     st[u]=true;
//     for(int i=h[u];i!=-1;i=ne[i])
//     {
//         int j=e[i];
//         if(!st[j])
//             dfs(j);
//     }
// }
//树的重心
//返回以u为根的子树中 点的数量
int dfs(int u)
{
    st[u]=true;
    int sum=1;
    int res=0;//将点删去后每个连通块的最大值res
    int j=e[i];
    if(!st[j])
    {
        int s=dfs(j);
        res=max(res,s);
        sum+=s;
    }
    res=max(res,n-sum);    
    ans=min(res,ans);
    return sum;
}



int main()
{
    memset(h,-1,sizeof h);
    
    
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        add(a,b),add(b,a);
    }
    dfs(1);
    cout<<ans<<endl;

    system("pause");
    return 0;

}
1:43:10