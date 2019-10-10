//p1583
#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;

const int N=20010;
int E[15];
int W[N];
int n,k;
struct peo
{
    int w;
    int num;
    int d;
    int c;
}p[N];

bool cmp(peo a,peo b)
{
    if(a.w!=b.w)
        return a.w>b.w;
    else
    {
        return a.num<b.num;
    }
    
}

int main()
{
    cin>>n>>k;
    for(int i=1;i<=10;i++)
    {
        cin>>E[i];
    }
    for(int i=1;i<=n;i++)
    {
        p[i].num=i;
        cin>>W[i];
        p[i].w=W[i];
    }
    sort(p+1,p+n+1,cmp);

    for(int i=1;i<=n;i++)
    {
        p[i].d=i;
        p[i].c=(i-1)%10+1;
        p[i].w=p[i].w+E[p[i].c];
    }
    sort(p+1,p+n+1,cmp);
    for(int i=1;i<=k;i++)
        cout<<p[i].num<<" ";
    system("pause");
    return 0;
}