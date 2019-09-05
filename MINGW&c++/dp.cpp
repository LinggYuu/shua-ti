//背包问题
//01背包
// #include<iostream>
// #include<algorithm>
// using namespace std;

// const int N=1010;
// int n,m;//个数，容量
// int v[N],w[N];//体积，价值
// int f[N][N];//状态

// int main()
// {  
//     cin>>n>>m;//个数，容量
//     for(int i=1;i<=n;i++)
//         cin>>v[i]>>w[i];// 所有物品
//     for(int i=1;i<=n;i++)
//         for(int j=0;j<=m;j++)  
//         {
//             f[i][j]=f[i-1][j];
//             if(j>=v[i]) 
//                 f[i][j]=max(f[i][j],f[i-1][j-v[i]]+w[i]);
//         }
//     cout<<f[n][m]<<endl;
//     return 0;
// }


//完全背包问题
// #include<iostream>
// #include<algorithm>
// using  namespace std;

// const int N=1010;

// int n,m;
// int v[N],w[N];
// int f[N][N];

// int main()
// {
//     cin>>n>>m;
//     for(int i=0;i<n;i++)
//         cin>>v[i]>>w[i];
    
//     for(int i=1;i<=n;i++)
//         for(int j=0;j<=m;j++)
//             for(int k=1;k*v[i]<=j;k++)
//                 f[i][j]=max(f[i-1][j],f[i-1][v[i]-k*j]+w[i]*k);
//     cout<<f[n][m];

//     system("pause");
//     return 0;
// }





//线性dp 
//数字三角形
#include<iostream>
#include<algorithm>
using namespace std;
const int N=510,INF=1e9;
int n;
int a[N][N];
int f[N][N];

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=i;j++)
            cin>>a[i][j];
    for(int i=0;i<=n;i++)
        for(int j=0;j<=i+1;j++)
            f[i][j]=-INf;
    f[1][1]=a[1][1];
    for(int i=2;i<=n;i++)
        for(int j=1;j<=i;j++)
            f[i][j]=max(f[i-1][j-1]+a[i][j],f[i-1][j]+a[i][j]);
    int res=-INF;
    for(int i=1;i<=n;i++)
        res=max(res,f[n][i]);
    cout<<res;

system("pause");
return 0;
}



//最长上升子序列
#include<iostream> 
#include<algorithm>
using namespace std;

const int N=1010;

int n;
int a[N],f[N];
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {    
        f[i]=1;
        for(int j=1;j<i;j++)
            if(a[j]<a[i])
                f[i]=max(f[i],f[j]+1);

    }

}