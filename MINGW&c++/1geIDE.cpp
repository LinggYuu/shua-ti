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
        for(int j=1;j<=n;j++)//遍历所有点
        {
            if(!st[j]&&(t==-1 || dist[t]>dist[j]))
                t=j;
        }
        st[t]=true;

        for(int j=1;j<=n;j++)
        {
            dist[j]=min(dist[j],dist[t]+g[t][j]);
        }
    }
    if(dist[n]==0x3f3f3f)
        return -1;
    else
        return dist[n];
}

int main()
{
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