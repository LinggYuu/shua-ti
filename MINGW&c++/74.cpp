// T99369
#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
const int N=1010,M=2010;

typedef pair<int,int>PII;
int n,m;
int h[N],w[N],e[N],ne[N],idx;
int dist[N];
bool st[N];

void add(int a,int b)
{
    e[idx]=b;
    w[idx]=1;
    ne[idx]=h[a];
    h[a]=idx++;//a指向idx
}
int spfa()
{
    memset(dist,0x3f3f,sizeof dist);
    dist[1]=0;
    queue<int>q;//定义队列存储所有待更新的点
    q.push(1);
    st[1]=true;//当前点是否在队列当中，防止存重复点
    while(q.size())
    {
        int t=q.front();
        q.pop();
        st[t]=false;
        for(int i=h[t];i!=-1;i=ne[i])
        //遍历t的所有出边
        //i和ne[i]指的应该都是下标
        {
            int j=e[i];
            if(dist[j]>dist[t]+w[i])
            {
                dist[j]=dist[t]+w[i];
                if(!st[j])
                {
                    q.push(j);
                    st[j]=true;
                }
            }
        }
    }
    if(dist[n]==0x3f3f3f)
        return -1;
    return dist[n];
}

int main()
{
    scanf("%d%d",&n,&m);
    memset(h,-1,sizeof(h));
    while(m--)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        add(a,b);
    }
    
    int t=spfa();

    if(t==-1)
        cout<<t;
    else
        printf("%d\n",t);

    system("pause");
    return 0;
}

