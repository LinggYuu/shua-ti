// // 1 2 4 8 …… 2^k
// // 2^k前的n项和:2^k - 1
// //背包问题
// 要求在循环过程中后者所需要的前者状态已经被求过

// //01背包

// // 直接求f[i][j]含j的不好求
// // 含j曲线求值，f[i-1][j-v[i]]这个东西已经在上一层求过所以可以

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
// int main()
// {
//     优化成一维，因为f[i][j]在算时只用到了i-1即上一层，可用滚动数组，
//     但要从大到小因为这样j-v[i]讲在j之后算，也就是在max时用的是[i-1][j-v[i]]
// for(int i=1;i<=n;i++)
//     cin>>v[i]>>w[i];
// for(int i=1;i<=n;i++)
// {
//     for(int j=m;j>=v[i];j++)
//         f[j]=max(f[j],f[j-v[i]+w[i]]);
// }
// }






// //完全背包问题

// f[i][j]=f[i-1][j];
// for(int  k=0;k*v[i]<j;k++)
// {
//     f[i][j]=max(f[i][j],f[i-1][j-k*v[i]]+k*w[i]);
// }


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
//     for(int i=1;i<n;i++)
//         cin>>v[i]>>w[i];
    
//     for(int i=1;i<=n;i++)
//         for(int j=0;j<=m;j++)
//             for(int k=1;k*v[i]<=j;k++)
//                 f[i][j]=max(f[i-1][j],f[i-1][v[i]-k*j]+w[i]*k);
//     cout<<f[n][m];                     // 这一项是f[i][j-v[i]]+w[i];

// //优化1
//     for(int i=1;i<=n;i++)
//     {
//         for(int j=0;j<=m;j++)
//         {
//             f[i][j]=f[i-1][j];
//             if(j>=v[i])f[j]=max(f[i-1][j],f[i][j-v[i]]+w[i]); 
//         }
//     }

// // 优化2

//     for(int i=1;i<=n;i++)
//     {
//         for(int j=v[i];j<m;j++)
//         {
//             f[j]=max(f[j],f[j-v[i]]+w[i]);
//         }
//     }
// }



// // 多重背包问题
// #include<iostream>
// #include<algorithm>
// using namespace std;
// const int N=1010,M=2010;

// int n,m;
// int v[N],w[N],s[N];
// int f[N][N];

// int main()
// {
//     cin>>n>>m;
//     for(int i=1;i<=n;i++)
//     cin>>v[i]>>w[i]>>s[i];
//     for(int i=1;i<=n;i++)//枚举哪一个
//     {
//         for(int j=0;j<=m;j++)//枚举体积
//         {
//             for(int k=0;k<=s[i]&&k*v[i]<=j;k++)//枚举选几个
//             {
//                 f[i][j]=max(f[i-1][j],f[i-1][j-v[i]*k]+w[i]*k);
//             }
//         }
//     }//暴力解法与完全背包暴力解相似

//     //youhua  二进制优化后是个01背包
//     cin>>n>>m;
//     int cnt=0;
//     for(int i=1;i<=n;i++)
//     {
//         int a,b,s;
//         cin>>a>>b>>s;
//         int k=1;
//         while(k<=s)
//         {
//             cnt++;
//             v[cnt]=a*k;
//             w[cnt]=b*k;
//             s-=k;
//             k*=2;
//         }
//         if(s>0)
//         {
//             cnt++;
//             v[cnt]=a*s;
//             w[cnt]=b*s;
//         }

//     }
//     n=cnt;

//     for(int i=1;i<=n;i++)
//     {
//         for(int j=m;j<=m;j++)
//         {
//             f[j]=max(f[j],f[j-v[i]]+w[i]);
//         }
//     }
// }

// 分组背包问题(直接优化版)

// max(f[i-1][j],f[i-1],j-v[i][k]+w[i][k])

#include<iostream>
#include<algorithm>
using namespace std;

const int N=110;
int n,m;
int v[N][N];//N个组，每个组有N种物品
int w[N][N];//同上
int s[N];//第N组的物品种类数量
int f[N];
int main()
{ 
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<s[i];j++)
        {
            cin>>v[i][j]>>w[i][j];
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=m;j>=0;j--)
        {
            for(int k=0;k<s[i];k++)
            {
                if(v[i][k]<=j)
                f[j]=max(f[j],f[j-v[i][k]]+w[i][k]);
            }
        }
    }

}