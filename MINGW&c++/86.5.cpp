// p1037
#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
using namespace std;

int h[15][15];
int s[15],l[15];//s存左部，l存长度
int num,x[30],nn[500];
int n,k,t,tt=-1;
int st[15];
string words;
void dfs(int c)
{
    st[c]=1;
    for(int i=1;i<=l[c];i++)
    {
        if(st[h[c][i]])
            continue;
        num++;
        dfs(h[c][i]);
    }
}
void mul(int a[],int b)
{
    for(int i=1;i<=a[0];i++)
        a[i]*=b;
    for(int i=1;i<=a[0];i++)
    {
        if(a[i]>=10)
        {
            a[i+1]+=a[i]/10;
            a[i]%=10;
            if(i==a[0]) 
                a[0]++;
        }
    }
}
int main()
{
    memset(l,0,sizeof(l));
    cin.tie();
    x[0]=1;
    x[1]=1;
    cin>>words>>k;
    for(int i=1;i<=k;i++)
    {
        int a,b;
        cin>>a>>b;
        h[a][++l[a]]=b;
        if(l[a]==1)
        {
            s[++tt]=a;
        }
    }
    for(int i=0;i<words.size();i++)
    {
        memset(st,0,sizeof(st));
        dfs(words[i]-'0');
        mul(x,num+1);
        num=0;
    }
    for(int i=x[0];i>=1;i--)
    {
        cout<<x[i];
    }

    
    system("pause");
    return 0;
}