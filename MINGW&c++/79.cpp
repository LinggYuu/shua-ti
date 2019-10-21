// p1101
#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=105;
int n;
int dx[8]={0,0,-1,1,-1,1,-1,1};
int dy[8]={-1,1,0,0,-1,-1,1,1};
char w[N][N];
int x[N],y[N];
int xx,yy;
string p="izhong";
bool st[N][N],k[N][N];
void dfs(int a,int b,int cnt)
{
    if(cnt>5)
    {
        for(int i=0;i<=6;i++)
        {
            // cout<<x[i]<<" "<<y[i];
            st[x[i]][y[i]]=1;
        }
        // cout<<endl;
    }
    if(cnt==0)
    {
        for(int i=0;i<8;i++)
        {
            if(w[a+dx[i]][b+dy[i]]==p[cnt])
            {
                // cout<<p[cnt];
                xx=dx[i];
                yy=dy[i];
                x[6]=a;
                y[6]=b;
                x[cnt]=a+xx;
                y[cnt]=b+yy;
                dfs(a+xx,b+yy,cnt+1);
            }
        }
    }
    else
    {
    if(w[a+xx][b+yy]==p[cnt])
    {
        x[cnt]=a+xx;
        y[cnt]=b+yy;
        dfs(a+xx,b+yy,cnt+1);
    }
    }

}
int main()
{
    cin>>n;
    for(int i=2;i<=n+1;i++)
    {
        for(int j=2;j<=n+1;j++)
        {
            cin>>w[i][j];
        }
    }
    for(int i=2;i<=n+1;i++)
    {
        for(int j=2;j<=n+1;j++)
        {
            if(w[i][j]=='y')
            {
                dfs(i,j,0);
            }
        }
    }
    for(int i=2;i<=n+1;i++)
    {
        for(int j=2;j<=n+1;j++)
        {
            if(st[i][j]!=1)
            {
                w[i][j]='*';
            }
        }
    }
    for(int i=2;i<=n+1;i++)
    {
        for(int j=2;j<=n+1;j++)
        {
        cout<<w[i][j];
        }
        cout<<endl;
    }

    system("pause");
    return 0;

}



// conclusion:
//     枚举到值为"y"的位置
//     以此位置进行大法师，第一次大法师得到方向
//     第二次大法师沿着该方向一直大法师，假如cnt超过
//     5则该条成立，将这些位置的状态全改为1，然后顺其自然
//     35，36行是回溯 