// p1160
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=100010,M=100010;
int n,m,idx,head;
int e[N],l[N],r[N],st[M];
int k,p;

void init()
{
    l[N-1]=0;
    r[0]=N-1;
    idx=1;
}

void add(int k,int x)
{
    e[idx]=x;
    l[idx]=k;
    r[idx]=r[k];
    l[r[k]]=idx;
    r[k]=idx;
    idx++;
}

void del(int k)
{
    r[l[k]]=r[k];
    l[r[k]]=l[k];
}


int main()
{
    memset(st,0,sizeof st);
    init();
    scanf("%d",&n);
    add(0,1);
    for(int i=2;i<=n;i++)
    {
        int k,p;
        scanf("%d %d",&k,&p);
        {
            if(p==0)//zuo
            {
                add(l[k],idx);
            }
            else if(p==1)//you
            {
                add(k,idx);
            }   
        }    
        
    }   
    // cout<<e[0]<<endl;
    // cout<<e[1]<<endl;
    // cout<<e[2]<<endl;
    // for(int i=2;e[i];i=r[i])
    // {
    //     cout<<e[i]<<',';
        
    // }
    // cout<<endl;

    scanf("%d",&m);
    while(m--)
    {
        int t;
        scanf("%d",&t);
        st[t]+=1;
        if(st[t]>1)
            continue;
        del(t);
    }
    
    for(int i=0;e[i]||i==0;i=r[i])
    {
        if(i==0)
            continue;
        if(i==r[0])
        {
            printf("%d",e[i]);
            continue;
        }
        printf(" %d",e[i]);
    }

    
    system("pause");
    return 0;
}