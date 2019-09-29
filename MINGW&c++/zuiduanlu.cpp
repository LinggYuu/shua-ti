// 最短路
//源点其实就是起点，汇点其实就是终点
//  ①单源最短路，从1号点到其他点最短路
//  ②多源汇最短路，任选两个点的最短路


// 如何把原问题抽象成最短路问题，--建图


// 算法实现

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
    for(int i=0;i<n;i++)
    {
        int t=-1;
        for(int j=1;j<=n;j++)//找距离最短点
        {
            if(!st[j]&&(t==-1||dist[t]>dist[j]))
            //t==-1表示没确定 dist[t]>dist[j]表示点t到原点的距离大于点j到原点距离
                t=j;//更新t
        }
        if (t==n)
            break;
        st[t]=true;

        for(int j=1;j<=n;j++)
            dist[j]=min(dist[j],dist[t]+g[t][j]);
            //若t,i间没边，则g。。为无穷大
    }
    if(dist[n]==0x3f3f3f)
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