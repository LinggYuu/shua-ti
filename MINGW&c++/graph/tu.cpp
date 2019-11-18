// // // dp是没有环的最短路
// // //只有边权都是1时才能用bfs求最短路
// // //树是特殊的图，无环，连通


// // // 有向图、无向图
// // // a->b  , a-b(a->b,b->a就是a-b)

// // // 图的存储
// // //邻接矩阵g[a,b]
// // //存储a到b的一条边的信息,值可以表示有没有，权重等
// // //比较适合用稠密图，用的比较少

// // // 图的邻接表存储(单链表)用得较多
// // // n个点就开n个单链表
// // // 图 2->1,1->4,1->3,3->4,2->4
// // // 4个点4个单链表
// // // 1:->o3->o4->o/
// // // 2:->o1->o4->o/
// // // 3:->o4->o/
// // // 4->o/

// // // 多条边一般从头插
// // #include<iostream>
// // #include<algorithm>
// // #include<cstring>
// // #include<algorithm>
// // using namespace std;

// // const int N=100010,M=N*2;

// // int h[N]/*n个头*/,e[M],ne[M],idx;
// // bool st[N];
// // void add(int a,int b)//一条(a,b)
// // {
// //     e[idx]=b;
// //     ne[idx]=h[a];
// //     h[a]=idx++;
// // }

// // void dfs(int u)
// // {
// //     st[u]=true;//该点已被访问过,被搜过
// //     for(int i=h[u];i!=-1;i=ne[i])
// //     {
// //         int j=e[i];
// //         if(!st[j])
// //             dfs(j);
// //     }

// // }

// // int main()
// // {

// //     memset(h,-1,sizeof h);

// // }


// // 图的遍历

// //DFS


// // 树的重心

// #include<iostream>
// #include<algorithm>
// using namespace std;
// const int  N=100010,M=N*2;//N点，M边
// int n,m;
// int h[N],e[M],ne[M],idx;
// //idx边序号，第一条边，第二条边....
// bool st[N];
// int ans=N;//为最小的最大值


// void add(int a,int b)
// {
//     e[idx]=b;
//     ne[idx]=h[a];
//     h[a]=idx++;
// }

// int dfs(int u)//返回以u为根的子树大小
// {
//     st[u]=true;//该点已被访问过,被搜过
//     int sum=1,res=0;
//     //res为把这个点删掉后，
//     //每个连通块大小最大值   
//     for(int i=h[u];i!=-1;i=ne[i])
//     {
//         int j=e[i];
//         if(!st[j])
//         {
//             int s=dfs(j);
//             res= max(res,s);
//             sum+=s;
//             //以j为根的子树大小是以
//             //u为根的子树大小的一部分
//         }
//     }
//     res=max(res,n-sum);
//     ans=min(ans,res);
//     return sum;
// }
// int main()
// {
//     cin>>n;
//     memset(h,-1,sizeof h);
//     for(int i=0;i<n-1;i++)
//     {
//         int a,b;
//         cin>>a>>b;
//         add(a,b),add(b,a);
//     }
//     dfs(1);

//     cout<<ans<<endl;
//     system("pause");
//     return 0;
// }



// BFS
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=100010;
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
    q[0]=1;//第一个元素起点1
    memset(d,-1,sizeof d);//初始化距离
    d[1]=0;
    while(hh<=tt)
    {
        int t=q[hh++];
        for(int i=h[t];i!=-1;i=ne[i])
        {
            int j=e[i];
            if(d[j]==-1)
            {
                d[j]=d[t]+1;
                q[++tt]=j;
            }

        }

    }
    return d[n];
}

int main()
{
    cin>>n>>m;
    memset(h,-1,sizeof h);
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        add(a,b);
    }
    cout<<bfs()<<endl;

    system("pause");
    return 0;
}

// 有向无环图也被称为拓扑图
// 一个有向无环图一定存在至少一个入度为0的点
// 所有的边都从前指向后
// 有向图的拓扑(宽搜应用)