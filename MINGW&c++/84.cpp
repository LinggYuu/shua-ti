//p1996
#include<iostream>
#include<algorithm>
using namespace std;

const int N=100010;
int n,m;
int q[N];
int hh=1,tt=0;
// q[++tt]=x  插入
// q[hh++]  出
//if (hh<=tt) 不空


int main()
{

    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        q[++tt]=i;
    }
    int cnt=0;
    // for(int i=1;i<=n;i++)
    // {
    //     cout<<q[i];
    // }
    while(hh<=tt)
    {
        cnt++;
        if(cnt==m)
        {
            cout<< q[hh++]<<" ";
            cnt=0;
            continue;
        }

            q[++tt]=q[hh]; 
            hh++;
 
    }

    


    system("pause");
    return 0;
}