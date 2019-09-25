// p1118
#include<iostream>
#include<algorithm>
using namespace std;

const  int N=15;
int num[N],yh[12][12],zz[N];
bool st[N];
int n,sum,minnum=100000000;


void inityh()
{
    yh[1][1]=1;
    for(int i=2;i<=10;i++)
    {
        yh[i][1]=1;
        yh[i][i]=1;
        for(int j=2;j<=i;j++)
        {
            yh[i][j]=yh[i-1][j]+yh[i-1][j-1];
        }
    }
}


void dfs(int t,int zs)
{
    if(zs>sum)
        return;
    if(t==n+1&&zs==sum)
    {
        // int s=0;
        // for(int i=1;i<=n;i++)
        // {
        //     s+=num[i]*yh[n][i];
        //     if(s>sum)
        //         return;
        // }
        // if(s==sum)
        // {
            int x=1;
            int nu=0;
            for(int i=n;i>0;i--)
            {
                nu+=num[i]*x;
                x=x*10;
            }
            if(nu<minnum)
            {
                minnum=nu;
                for(int i=1;i<=n;i++)
                zz[i]=num[i];

            }
        // }
    for(int i=1;i<=n;i++)
    {
    if(st[i]==1)
        continue;
    num[t]=i;
    zs+=num[t]*yh[n][t];
    st[i]=1;
    dfs(t+1,zs);
    zs-=num[t]*yh[n][t];
    st[i]=0;
    }
    }
    


}


int main()
{
    cin.tie();
    cin>>n>>sum;
    inityh();
    dfs(1,0);
    for(int k=1;k<=n;k++)
        cout<<zz[k]<<" ";
    cout<<endl;
    system("pause");
    return 0;

}