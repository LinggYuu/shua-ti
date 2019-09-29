// p1434
#include<iostream>
#include<algorithm>
using namespace std;

const int N=105;
int R,C;//行数，列数
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
int map[N][N];
int st[N][N];
int ans[N][N];
int maxnum;

int dfs(int x,int y)
{
    if(st[x][y]!=0)
    {
        return ans[x][y];
    }
    ans[x][y]=1;
    st[x][y]=1;
    for(int i=0;i<4;i++)
    {
        if(map[x+dx[i]][y+dy[i]]<map[x][y])
        {
            ans[x][y]=max(ans[x][y],dfs(x+dx[i],y+dy[i])+1);//6   
        }
    }
    return ans[x][y];
}
int main()
{
    cin>>R>>C;
    memset(map,0X1,sizeof(map));//16843009
    for(int i=1;i<=R;i++)
    {   
        for(int j=1;j<=C;j++)
        {
            cin>>map[i][j];
        }
    }
    for(int i=1;i<=R;i++)
    {
        for(int j=1;j<=C;j++)
        {     
            dfs(i,j);
            maxnum=max(dfs(i,j),maxnum);
        }
    }
    cout<<maxnum<<endl;
    system("pause");
    return 0;
}