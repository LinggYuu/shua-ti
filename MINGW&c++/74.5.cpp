
#include<iostream>
#include<algorithm>

using namespace std;

const int N=2010,INF=0x3f3f3f;
int d[N][N];
int n,m,ci;
int a,b;
int jl[N*N][2];

void floyd()
{
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }
}

int main()
{
    cin>>n>>m;
    int nn=n,mm=m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==j) 
                d[i][j]=0;
            else 
                d[i][j]=INF;
        }
    }
    int i=0;
    m-=1;
    while(m--)
    {
    
        cin>>a>>b;
        jl[i][0]=a;
        jl[i++][1]=b;
        d[a][b]=min(d[a][b],1);
    }
    floyd();
    cin>>a>>b;
    jl[i][0]=a;
    jl[i++][1]=b;
    cout<<nn<<mm<<endl;
    for(int j=0;j<i;j++)  
    {  
        if(d[jl[j][0]][jl[j][1]]>INF/2) 
        {
            cout<<jl[j][0]<<' '<<jl[j][1]<<' '-1;
        }
        else 
        {
            cout<<jl[j][0]<<' '<<jl[j][1]<<' '
                <<d[jl[j][0]][jl[j][1]]<<endl;
        }
    }

    system("pause");
    return 0;
}