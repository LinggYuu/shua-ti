// dp是没有环的最短路
//只有边权都是1时才能用bfs求最短路
//树是特殊的图，无环，连通


// 有向图、无向图
// a->b  , a-b(a->b,b->a就是a-b)

// 图的存储
//邻接矩阵g[a,b]
//存储a到b的一条边的信息,值可以表示有没有，权重等
//比较适合用稠密图，用的比较少

// 图的邻接表存储(单链表)用得较多
// n个点就开n个单链表
// 图 2->1,1->4,1->3,3->4,2->4
// 4个点4个单链表
// 1:->o3->o4->o/
// 2:->o1->o4->o/
// 3:->o4->o/
// 4->o/

// 多条边一般从头插
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N=100010,M=N*2;

int h[N]/*n个头*/,e[M],ne[M],idx;
bool st[N];
void add(int a,int b)//一条(a,b)
{
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx++;
}

void dfs(int u)
{
    st[u]=true;//该点已被访问过
    for(int i=h[u];i!=-1;i=ne[i])
    {
        int j=e[i];
        if(!st[j])
            dfs(j);
    }

}

int main()
{

    memset(h,-1,sizeof h);

}


// 图的遍历

//DFS


