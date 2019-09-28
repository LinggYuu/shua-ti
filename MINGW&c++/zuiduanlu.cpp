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
int g[N][N];
int dist[N];
bool st[N];

int main()
{
    scanf("%d%d",&n,&m);
    memset(g,0x3f,sizeof g);
    // for(int i=1;i<=n;i++)
    //     for(int j=1;j<=n;j++)
    //         if(i==j)g[i][j]=0;
    //         else g[i][j]=INF;
        
}