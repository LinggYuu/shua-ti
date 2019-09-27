
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
    for(int i=h[u];i!=-1;i=ne[i])
    {
        int j=e[i];//e[i]为头结点，即j为根
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
}



int main()
{
    memset(h,-1,sizeof h);
    
    for(int i=0;i<n-1;i++)
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

// bfs
// 重边 a有两条指向b的边

// 自环 自己指自己
int n,m;
int h[N],e[N],ne[N],idx;
int d[N],q[N];

void add(int a,int b)
{
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx++;
}
int bfs()
{
    int hh=0,tt=0;
    q[0]=1;
    memset(d,-1,sizeof d);
    d[1]=0;
    while(hh<=tt)//队列不空
    {
        int t=q[hh++]; //取队头
        for(int i=h[t];i!=-1;i=ne[i])
        {
            int j=e[i];
            if(d[j]==-1)//j未被扩展
            {
                d[j]=d[t]+1;//扩展，为到初始点距离（应该）
                q[++tt]=j;//存入
            }
        }
    }
}

// 拓扑序列，有向图(无向图没有)
// 1->2->3
// 1->3
// 123为拓扑序列
// 起点在终点前
// 当按拓扑序排好后，所有边都是从前走向后的 
// 有环无拓扑序
// 有向无环的图一定是存在拓扑序列的，存在入度为0的点
// 入度(有多少条边指向自己)，出度(自己指向多少条边))
// 入度为0可作为起点
// 将所有入度为0的点入队

const int N=10010;
int n,m;
int e[N],ne[N],idx;
int q[N],d[N];

void add(int a,int b)//a->b
{
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx++;
}

bool topsort()
{
    int hh=0,tt=-1;
    for(int i=1;i<=n;i++)
    {
        if(!d[i])
        {
            q[++tt]=i;
        }
    }
    while(hh<=tt)
    {
        int t=q[hh++];
        for(int i=h[t];i!=-1;i=ne[i])
        {
            int j=e[i];
            d[j]--;
            if(d[j]==0)
                q[++tt]=j;

        }

    }
    return tt==n-1;
}


int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        add(a,b);
        d[b]++;
    }
    if(topsort())
    {

    }
    else
        puts("-1");

}