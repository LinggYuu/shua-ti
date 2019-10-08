// p1309
#include<iostream>
#include<algorithm>
using namespace std;

const int N=100010,R=60,Q=2*N;
struct pl
{
    int num;//编号
    int ab;//能力
    int score;
}xs[2*N];
pl win[2*N],lose[2*N],hb[2*N];
int n,r,q;

int t,tt;//lose,win

bool cmp(pl a,pl b)
{
    if(a.score!=b.score)//按什么排
        return a.score>b.score;//按分数大的在前
    else
        return a.num<b.num;//按编号小的在前
}

void ms()
{ 
    int cnt=1;
    int c=1;
    int l=1,w=1;
    int cntt=0;
    while(l<=n&&w<=n)
    {
        if(cmp(lose[l],win[w]))
        {
            hb[c++]=lose[l++];
            cntt=c-1;
            // cout<<hb[cntt].score<<endl;
        }
        else
        {
            hb[c++]=win[w++];
            cntt=c-1;
            // cout<<hb[cntt].score<<endl;
        }
    }
    while(l<=n)
    {
        hb[c++]=lose[l++];
    }
    while(w<=n)
    {
        hb[c++]=win[w++];
    }
    for(int i=1;i<=2*n;i++)
    {
        xs[i]=hb[i];
        // cout<<hb[i].num;
    }
    // cout<<c-1;
    // cout<<endl;

}

int main()
{
    cin>>n>>r>>q;
    for(int i=1;i<=2*n;i++)
    {
        xs[i].num=i;//编号
        cin>>xs[i].score;//当前成绩
    }
    for(int i=1;i<=2*n;i++)
    {
        cin>>xs[i].ab;//能力
    }
    sort(xs+1,xs+2*n+1,cmp);
    //起始地址，最后一个的后一个的地址
    for(int i=1;i<=2*n;i++)
    {
        // cout<<xs[i].num;
    }
    // cout<<endl;
    while(r--)
    {
        t=1,tt=1;
        for(int j=1;j<=2*n-1;j+=2)//根据能力比试
        {
            if(xs[j].ab>xs[j+1].ab)
            {
                xs[j].score+=1;
                lose[t++]=xs[j+1];
                win[tt++]=xs[j];
            }
            else
            {
                xs[j+1].score+=1;
                lose[t++]=xs[j];
                win[tt++]=xs[j+1];
            }
        }
        tt-=1;
        t=tt;
        ms();
    }

    // for(int i=1;i<=2*n;i++)
    // {
    //     cout<<hb[i].num;
    // }
    // cout<<endl;
    cout<<hb[q].num;
    system("pause");
    return 0;

}