#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

typedef pair<int,int> pl;
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
const int N=35;
int n;
int a[N][N];
int st[N][N];
pl p[N*N];

void bfs(int x,int y)
{
    int h=0;
    queue<pl>q;
    p[0]={x,y};
    q.push(p[h]);
    a[p[0].first][p[0].second]=2;
    while(!q.empty())
    {
        auto t=q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {   
            int xx=t.first+dx[i];
            int yy=t.second+dy[i];
            if(a[xx][yy]==0&&xx<n&&xx>=0&&yy>=0&&yy<n)
            {
                a[xx][yy]=2;
                p[++h]={xx,yy};
                q.push(p[h]);
            }
        }
    }
}



int main()
{
    cin.tie();
    int sx=0,sy=0,f=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(a[i][j]==1&&f==0)
            {
                for(int k=i+1;k<n;k++)
                {
                    if(a[k][j]==0&&f==0)
                    {
                        sx=k;
                        sy=j;
                        f=1;
                        break;
                    }
                }
            }
        }
    }
    cout<<endl;
    bfs(sx,sy);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            {cout<<a[i][j]<<" ";
            if(j==n-1)
                cout<<endl;}








    //     for(int i=0;i<n;i++)
    // {
    //     for(int j=0;j<n;j++)
    //     {
    //         cout<<a[i][j]<<" ";
    //         if(j==n-1)
    //         {
    //             cout<<endl;
    //         }        
    //     }
    // }

    system("pause");
    return 0;

}