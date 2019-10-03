// 最短路
//源点其实就是起点，汇点其实就是终点
//  ①单源最短路，从1号点到其他点最短路
//  ②多源汇最短路，任选两个点的最短路


// 如何把原问题抽象成最短路问题，--建图


// 算法实现



//所有边皆为正数，要求一定不能存在负权边
//Dijkstra，贪心
// 有a->b,b->a等价于有一条a到bの无向边
// 稠密图用邻接矩阵来写，稀疏图用邻接表来写
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=510;
int n,m;
int g[N][N];//用邻接矩阵存
int dist[N];//从起点走到每个点的当前最短距离
bool st[N];//是否已确定

int dijkstra()
{
    memset(dist,0x3f,sizeof dist);
    dist[1]=0;//1号点距离初始化为零
    for(int i=0;i<n;i++)//n次迭代确定n个点
    {
        int t=-1;
        for(int j=1;j<=n;j++)//找距离最短点
        {
            if(!st[j]&&(t==-1||dist[t]>dist[j]))
            //t==-1表示没确定 dist[t]>dist[j]表示点t到原点的距离大于点j到原点距离
                t=j;//更新t，找到最短距离点，j点
        }
        if (t==n)
            break; 
        st[t]=true;

        for(int j=1;j<=n;j++)
            dist[j]=min(dist[j],dist[t]+g[t][j]);
            //若t,i间没边，则g。。为无穷大
    }
    if(dist[n]==0x3f3f3f)//1和n不连通
        return -1;
    else
    {
        return dist[n];
    }
     
}

int main()
{
    scanf("%d%d",&n,&m);//n点数，m边数
    memset(g,0x3f,sizeof g);
    // for(int i=1;i<=n;i++)
    //     for(int j=1;j<=n;j++)
    //         if(i==j)g[i][j]=0;
    //         else g[i][j]=INF;
    while(m--)//读入m条边
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        g[a][b]=min(g[a][b],c);//保留最短边
    }  
    int t=dijkstra();
    printf("%d\n",t);
    system("pause");
    return 0;
}

// 堆优化版的dijkstra算法 48.00
// 稀疏图，用堆，还没看先略过，1.04.11



//存在负权边

// Bellman-Ford算法
//如能求出最短距离，图中无负权回路
//限制边经过条数，有负环无所谓了
#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
const int N=510,M=10010;

int n,m,k;
int dist[N],backup[N];
struct Edge
{
    int a,b,w;
}edge[M];

int bellmanford()
{
    memset(dist,0X3f3f,sizeof dist);
    dist[1]=0;
    for(int i=0;i<k;i++)
    {
        memcpy(backup,dist,sizeof dist);//dist存入backup
        for(int j=0;j<m;j++)
        {
            int a=edge[j].a;
            int b=edge[j].b;
            int w=edge[j].w;
            dist[b]=min(dist[b],backup[a]+w);
        }
    }
    if(dist[n]>0X3f3f3f)
        return -1;
    else
        return dist[n];

}
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<m;i++)
    {
        int a,b,w;
        scanf("%d%d%d",&a,&b,&w);
        edge[i]={a,b,w};
    }
    int t=bellmanford();
    if(t==-1)
        puts("impossible");
    else 
        printf("%d\n",t);
}


//图中不能存在负环**
//SPFA算法   y总推荐（正权负权都能用）好用！
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

typedef pair<int,int>PII;
const int N=10010;
int n,m;
int h[N],w[N],e[N],ne[N],idx;
int dist[N];
bool st[N];

void add(int a,int b,int c)
{
    e[idx]=b;
    w[idx]=c;
    ne[idx]=h[a];
    h[a]=idx++;
}

int spfa()
{

    memset(dist,0x3f3f,sizeof dist);
    dist[1]=0;
    queue<int>q;//定义队列存储所有待更新的点
    q.push(1);
    st[1]=true;//当前点是否在队列当中，防止存重复点
    while(q.size())
    {
        int t=q.front();
        q.pop();
        st[t]=false;
        for(int i=h[t];i!=-1;i=ne[i])
        //遍历t的所有出边
        //i和ne[i]指的应该都是下标
        {
            int j=e[i];
            if(dist[j]>dist[t]+w[i])
            {
                dist[j]=dist[t]+w[i];
                if(!st[j])
                {
                    q.push(j);
                    st[j]=true;
                }
            }
        }
    }
    if(dist[n]==0x3f3f3f)
        return -1;
    return dist[n];
}

int main()
{
    scanf("%d%d",&n,&m);
    memset(h,-1,sizeof(h));
    while(m--)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        add(a,b,c);
    }
    int t=spfa();

    if(t==-1)
        puts("impossible");
    else
        printf("%d\n",t);

    return 0;
}

//1：45：30
// spfa求负环