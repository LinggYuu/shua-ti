//p1605
#include<iostream>

using namespace std;


int a[10][10];
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
bool st[10][10];
int N,M,T,sx,sy,fx,fy,zx,zy,ans=0;
void dfs(int sx,int sy)
{
    if(sx==fx&&sy==fy)
    {
        ans++;
        return;
    }
    for(int i=0;i<4;i++)
    { 
        sx+=dx[i];
        sy+=dy[i];
        if(a[sx][sy]==1&&st[sx][sy]==0)
        {
            st[sx][sy]=1;
            dfs(sx,sy);        
            st[sx][sy]=0;
        }    
        sx-=dx[i];
        sy-=dy[i];            
       
    }

}

int  main()
{
    cin>>N>>M>>T;
    cin>>sx>>sy>>fx>>fy;
    for(int i=1;i<=N;i++)
        for(int j=1;j<=M;j++)
            a[i][j]=1;
    for(int i=0;i<T;i++)
    {     
        cin>>zx>>zy;
        a[zx][zy]=0;
        if(zx==fx&&zy==fy)
        {
            cout<<0<<endl;
            return 0;
        }
    }
    st[sx][sy]=1;
    dfs(sx,sy);
    cout<<ans<<endl;
    system("pause");
    return 0;
}
