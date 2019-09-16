// p1141
#include<iostream>
#include<queue>
#include<string>
using namespace std;

typedef pair<int,int>pl;
const int N=1100;
int n,m,t=0;
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
int map[N][N];
int g[100100];
pl  d[N*N];

int bfs(int x,int y,int n)
{
    int cnt=1;
    queue<pl>q;
    d[t]={x,y};
    map[x][y]=-1;
    q.push(d[t]);
    while(!q.empty())
    {
        pl a=q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            int sx=a.first+dx[i];
            int sy=a.second+dy[i];
            if(sx<=n&&sx>=1&&sy<=n&&sy>=1
                &&map[sx][sy]!=map[a.first][a.second]
                &&map[sx][sy]!=-1)
                {
                    map[sx][sy]=-1;
                    d[++t]={sx,sy};
                    q.push(d[t]);
                    cnt++;
                }

        }
    }
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
        map[i][j]=0;
    return cnt;
}

int main()
{
    char a[1010];
    int x,y;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%s",a);
        for(int j=1;j<=n;j++)
        {
            map[i][j]=a[j-1]-'0';
        }
    }

        for(int k=0;k<m;k++)
        {
            scanf("%d%d",&x,&y);
            g[k]=bfs(x,y,n);
        }
    for(int i=0;i<m;i++)
        cout<<g[i]<<endl;

    system("pause");
    return 0;
}