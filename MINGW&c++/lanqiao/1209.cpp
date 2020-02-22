#include<iostream>
using namespace std;

const int N=10;
int n;
int cnt;
int st[N];
bool used[N];


int cal(int a,int b)
{
    int t=1;
    int c=0;
    for(int i=b;i>=a;i--)
    {
        c+=st[i]*t;
        t*=10;
    }
    return c;
}
void dfs(int u)
{
    if(u>9)
    {
       for(int i=1;i<=8;i++)
       {
           for(int j=i+1;j<=9;j++)
           {
               int a=cal(1,i);
               int b=cal(i+1,j);
               int c=cal(j+1,9);
               if(a*c+b==c*n)
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
    cin>>n;
    dfs(1);
    cout<<cnt;
    system("pause");
    return 0;
}