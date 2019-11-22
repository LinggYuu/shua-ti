// 最短路

// 1.单源最短路:
//     求从一个点到其他所有点的最短距离
// 2.多源汇最短路:
//     源点就是起点，汇点就是终点
//     任选两个点从其中一个点走到
//     另一个点的最短距离

// 1.:
//     所有边权都是正数
//         Dijkstra    稠密图（基于贪心）
//         堆优化版dijkstra    稀疏图  
//     有负权边
//         Bellman-Ford
//         SPFA
// 2:
//     Floyd（基于动态规划）


// m~n^2 稠密图
// m~n 稀疏图
// 稠密图用邻接矩阵
// 稀疏图用邻接表



// n为点数，m为边数

// n和m都是100000，稀疏图，边和点差不多
// n100m10000稠密图，边比点多很多

// 14:22

// 不要求其原理，侧重于实现，侧重于抽象



// 朴素版dijkstra
// 两个点间存在多条边(重边)的话只保留最短的那条边
// g[a][b]是a->b的边
// 循环n次确定n个点的最短距离
//每次确定一个离原点距离最短点
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=510;
int n,m;
int g[N][N];
int dist[N];//从一号点走到每个点的最短距离
bool st[N];//该点是否已确定

int dijkstra()
{   
    memset(dist,0x3f3f,sizeof dist);
    //所有距离初始化为∞
    dist[1]=0;//一号点距离初始化为0
    for(int i=0;i<n;i++)
    {
        int t=-1;//t为不在st中的距离最近的点，-1为未确定
        for(int j=1;j<=n;i++)//遍历所有点
        {
            if(!st[j]&&(t==-1 || dist[t]>dist[j]))
            {
                t=j;
            }
        }
            st[t]=true;
            for(int j=1;j<=n;j++)
            {
                dist[j]=min(dist[j],dist[t]+g[t][j]);
            }
        
    }

}

int main()
{
    cin.tie;
    cin>>n>>m;
    memset(g,0x3f3f,sizeof g);
    while(m--)//m条边
    {
        int a,b,c;
        cin>>a>>b>>c;
        g[a][b]=min(g[a][b],c);//重边防止
    }
    int t=dijkstra();
    cout<<t;
    system("pause");
    return 0;
}