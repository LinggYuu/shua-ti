// // p1118
// #include<iostream>
// #include<algorithm>
// using namespace std;

// const  int N=15;
// long long num[N],yh[13][13],zz[N];
// bool st[N];
// int n,sum,flag;

// void inityh()
// {
//     yh[1][1]=1;
//     for(int i=2;i<=12;i++)
//     {
//         yh[i][1]=1;
//         yh[i][i]=1;
//         for(int j=2;j<=i;j++)
//         {
//             yh[i][j]=yh[i-1][j]+yh[i-1][j-1];
//         }
//     }
//     return;
// }


// void dfs(int t,int zs)
// {
//     if(t==n+1)
//     {
//         if(zs==sum)
//         {
//             for(int i=1;i<=n;i++)
//             cout<<num[i]<<" ";
//             cout<<endl;
//             flag=1;
//         }
//     return;
//     }

//     for(int i=1;i<=n;i++)
//     {
//         if(st[i])
//             continue;
//         num[t]=i;
//         st[i]=1;
//         if((zs+num[t]*yh[n][t])>sum)
//         {
//             st[i]=0;
//             continue;
//         }
//         dfs(t+1,zs+num[t]*yh[n][t]);
//         st[i]=0;
//         if(flag)
//             return;
        
//     }
// }


// int main()
// {
//     cin.tie();
//     cin>>n>>sum;
//     inityh();
//     // for(int i=1;i<=12;i++)
//     //     cout<<yh[12][i]<<" ";
//     //     cout<<endl;
//     dfs(1,0);
//     // for(int k=1;k<=n;k++)
//     //     cout<<zz[k]<<" ";
//     cout<<endl;
//     system("pause");
//     return 0;

// }
// p1118
#include<iostream>
#include<algorithm>
using namespace std;

const  int N=15;
long long num[N],yh[13][13],zz[N];
bool st[N];
int n,sum,flag;

void inityh()
{
    yh[1][1]=1;
    for(int i=2;i<=12;i++)
    {
        yh[i][1]=1;
        yh[i][i]=1;
        for(int j=2;j<=i;j++)
        {
            yh[i][j]=yh[i-1][j]+yh[i-1][j-1];
        }
    }
    return;
}


void dfs(int t,int zs)
{
    if(t==n+1)
    {
        if(zs==sum)
        {
            for(int i=1;i<=n;i++)
            cout<<num[i]<<" ";
            flag=1;
        }
    return;
    }

    for(int i=1;i<=n;i++)
    {
        if(st[i])
            continue;
        num[t]=i;
        st[i]=1;
        if((zs+num[t]*yh[n][t])>sum)
        {
            st[i]=0;
            continue;
        }
        dfs(t+1,zs+num[t]*yh[n][t]);
        st[i]=0;
        if(flag)
            return ;
        
    }
}


int main()
{
    cin.tie();
    cin>>n>>sum;
    inityh();
    dfs(1,0);
    system("pause");
    return 0;

}