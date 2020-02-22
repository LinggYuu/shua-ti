#include<iostream>
using namespace std;

const int N=11;
int st[N];
bool used[N];
int cnt;
int a,b,c;
int num;

int cal(int l,int r)
{
    int s=0;
    for(int i=l;i<=r;i++)
    {
        s*=10;
        s+=st[i];
        
    }
    return s;
}

void dfs(int u)
{
    if(u>9)
    {
        for(int i=2;i<=9;i++)
        {
            for(int j=i+1;j<=9;j++)
            {
                a=cal(1,i-1);
                b=cal(i,j-1);
                c=cal(j,9);
                if ((num*b)==(a*b+c))
                    cnt++;
            }

        }
        return;
    }
    for(int i=1;i<=9;i++)
    {
        if(!used[i])
        {
            st[u]=i;
            used[i]=true;
            dfs(u+1);
            st[u]=0;
            used[i]=false;
        }
    }
}

int main()
{
    cin>>num;
    dfs(1);
    cout<<cnt;
    system("pause");
    return 0;
}