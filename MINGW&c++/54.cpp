// p1433
#include<iostream>
#include<cmath>
#include<algorithm>
#include <iomanip>
using namespace std;

int n;
double x;
double mi=100000.0;

struct ch
{
    double x;
    double y;
}che[20];
bool st[20];

double dis(ch a,ch b)
{
    double x1=a.x;
    double x2=b.x;
    double y1=a.y;
    double y2=b.y;
    double dd=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
    return dd;
}

void dfs(ch chi,int p)
{
    while(p>n)
    {
        double m=min(mi,x);
        mi=m;
        return;
    }

    for(int i=1;i<=n;i++)
    {
        if(st[i]==1)
            continue;
        x+=dis(chi,che[i]);
        st[i]=1;
        if(mi<x)
        {
            st[i]=0;
            x-=dis(chi,che[i]);
            continue;
        }
        dfs(che[i],p+1); 
        st[i]=0;
        x-=dis(chi,che[i]);
    }

}


int main()
{

    cin>>n;
    che[0].x=0,che[0].y=0;
    for(int i=1;i<=n;i++)
    {
        cin>>che[i].x>>che[i].y;
    }
    dfs(che[0],1);
    printf("%.2f",mi);
    
    system("pause");
    return 0;
}