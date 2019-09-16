// p1141//正解
#include<iostream>
#include<queue>
#include<string>
using namespace std;

typedef pair<int,int>pl;
const int N=1500;
int n,m,t=0;
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
int map[N][N];
int st[N][N];
int g[101000];
int ans[N][N];
pl  d[1000100];



int bfs(int x,int y)
{        
    if(ans[x][y]!=0)
        return ans[x][y];
    ans[x][y]=1;
    int cnt=1;
    int p=t;
    queue<pl>q;
    d[t]={x,y};
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
                &&!ans[sx][sy])
                {
                    ans[sx][sy]=1;
                    d[++t]={sx,sy};
                    q.push(d[t]);
                    cnt++;
                }
        }
    }
    for(int i=p;i<=t;i++)
        ans[d[i].first][d[i].second]=cnt;
    t++;
    return ans[x][y];
}

int main()
{
    cin.tie();
    string a;
    int x,y;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a;
        for(int j=1;j<=n;j++)
        {
            map[i][j]=a[j-1]-'0';
        }
    }

        for(int k=0;k<m;k++)
        {
            cin>>x>>y;
            g[k]=bfs(x,y);
        }
    for(int i=0;i<m;i++)
        cout<<g[i]<<endl;

    system("pause");
    return 0;
}