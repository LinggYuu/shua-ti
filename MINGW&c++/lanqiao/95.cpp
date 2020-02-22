#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=8;
char q[N][N],p[N][N];
int t;
int dx[5]={0,0,0,1,-1},dy[5]={0,1,-1,0,0};
int jl[505];

void c(int x,int y)
{
    for(int i=0;i<=4;i++)
    {
        if(x+dx[i]>=0&&x+dx[i]<=4&&y+dy[i]>=0&&y+dy[i]<=4)
        {
            if(q[x+dx[i]][y+dy[i]]=='0')
                q[x+dx[i]][y+dy[i]]='1';
            else if(q[x+dx[i]][y+dy[i]]=='1')
                q[x+dx[i]][y+dy[i]]='0';
        }

    }
}

int main()
{
    cin>>t;
    while(t--)
    {
        int bs=10;
        for(int i=0;i<=4;i++)
        {
            cin>>q[i];
        }//shuru
        for(int k=0;k<=31;k++)
        {
            int step=0;
            memcpy(p,q,sizeof q);
            for(int i=0;i<=4;i++)
            {
                if(k>>i&1)
                {
                    step++;
                    c(0,i);
                }
            }
            for(int i=0;i<=3;i++)
            {
                for(int j=0;j<=4;j++)
                {
                    if(q[i][j]=='0')
                    {
                        step++;
                        c(i+1,j);
                    }
                }
            }//genju shangyihang gai
            bool d=true;

            for(int i=0;i<=4;i++)
            {
                if(q[4][i]=='0')
                {
                    d=false;
                    break;
                }
            }
            if(d)
            {
                bs=min(bs,step);
            }
            memcpy(q,p,sizeof p);
        }
        if(bs>6)
            bs=-1;
        cout<<bs<<endl;
    }
    system("pause");
    return 0;
}