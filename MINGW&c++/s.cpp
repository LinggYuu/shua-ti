//dfs
//全排列问题
#include<iostream>
using namespace  std;

const int N=10;
int n;
int path[N];
bool st[N];

void dfs(int u)
{   
    if(u==n)
    {
        for(int i=0;i<n;i++)
            cout<<path[i]<<" ";
        cout<<endl;
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(!st[i])
        {
            path[u]=i;
            st[i]=true;
            dfs(u+1);//递归函数写完后恢复
            path[u]=0;
            st[i]=false;
        }
    }


}
// 剪枝，判断当前方案一定不合法，没有必要往下搜
//八皇后

#include<iostream>
using namespace std;

const int N=20;
int n;
char g[N][N]={'.'};
bool row[N],col[N],dj[N],fdj[N];

void dfs(int i)
{
    if(i==n)
    {
        for(int k=0;k<n;k++)
            puts(g[k]);
        puts("");
        return;
    }
    for(int j=0;j<n;j++)
    {   
        if(!col[j]
        &&(!dj[j+i])
        &&(!fdj[j-i+n]))
        g[i][j]='Q';
        col[j]=dj[i+j]=fdj[j-i+n]=1;
        dfs(i+1);
        col[j]=dj[i+j]=fdj[j-i+n]=0;
        g[i][j]='.';


    }


}


void dfs(int x,int y ,int s)
{
    if(y==n)
    {
        y=0;
        x++;
    }    
    if(x==n)
    {
        if(s==n)
        {
            for(int i=0;i<n;i++)
                puts(g[i]);
            puts("");
        }
        return;
    }

    dfs(x,y+1,s);
    if(!row[x]
    &&(!col[y])
    &&(!dj[x+y])
    &&(!fdj[y-x+n]))
    {
        g[x][y]='Q';
        row[x]=col[y]=dj[x+y]=fdj[y-x+n]=true;
        dfs(x,y+1,s+1);
        row[x]=col[y]=dj[x+y]=fdj[y-x+n]=false;
        g[x][y]='.';
    }



}

55:13