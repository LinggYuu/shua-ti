#include<iostream>
#include<queue>
using namespace std;
typedef pair<int,int> pl;
const int N=410;
int map[N][N];
int st[N][N];
int dx[8]={-1,1,2,2,1,-1,-2,-2};
int dy[8]={-2,-2,-1,1,2,2,-1,1};
pl s[N*N];
int n,m,sx,sy,t=0,tm=0;

void bfs(int x,int y)
{
    queue<pl>q;
    s[tm]={x,y};
    q.push(s[0]);
    while(!q.empty())
    {
        
        pl a=q.front();
        q.pop();
        for(int i=0;i<8;i++)
        {
            int xx=a.first+dx[i];
            int yy=a.second+dy[i];
            if(xx>=1&&xx<=n&&yy>=1&&yy<=m&&!st[xx][yy])
            {
                st[xx][yy]=1;
                map[xx][yy]=map[a.first][a.second]+1;
                s[++tm]={xx,yy};
                q.push(s[tm]);
            }
        }
    }
}
int main()
{
    cin.tie();
    cin>>n>>m>>sx>>sy;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            map[i][j]=-1;
        }
    map[sx][sy]=0;
    st[sx][sy]=1;
    bfs(sx,sy);

    for(int i=1;i<=n;i++)
    {   
        for(int j=1;j<=m;j++)
            {
                printf("%-5d", map[i][j]);
                if(j==m)
                    cout<<endl;
            }
    }
    
    system("pause");
    return 0;
}