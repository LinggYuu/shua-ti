//第一时刻，解啥设啥
// //背包问题
// //01背包
// // #include<iostream>
// // #include<algorithm>
// // using namespace std;

// // const int N=1010;
// // int n,m;//个数，容量
// // int v[N],w[N];//体积，价值
// // int f[N][N];//状态

// // int main()
// // {  
// //     cin>>n>>m;//个数，容量
// //     for(int i=1;i<=n;i++)
// //         cin>>v[i]>>w[i];// 所有物品
// //     for(int i=1;i<=n;i++)
// //         for(int j=0;j<=m;j++)  
// //         {
// //             f[i][j]=f[i-1][j];
// //             if(j>=v[i]) 
// //                 f[i][j]=max(f[i][j],f[i-1][j-v[i]]+w[i]);
// //         }
// //     cout<<f[n][m]<<endl;
// //     return 0;
// // }


// //完全背包问题
// // #include<iostream>
// // #include<algorithm>
// // using  namespace std;

// // const int N=1010;

// // int n,m;
// // int v[N],w[N];
// // int f[N][N];

// // int main()
// // {
// //     cin>>n>>m;
// //     for(int i=0;i<n;i++)
// //         cin>>v[i]>>w[i];
    
// //     for(int i=1;i<=n;i++)
// //         for(int j=0;j<=m;j++)
// //             for(int k=1;k*v[i]<=j;k++)
// //                 f[i][j]=max(f[i-1][j],f[i-1][v[i]-k*j]+w[i]*k);
// //     cout<<f[n][m];

// //     system("pause");
// //     return 0;
// // }





// //线性dp 
// //数字三角形
// #include<iostream>
// #include<algorithm>
// using namespace std;
// const int N=510,INF=1e9;
// int n;
// int a[N][N];
// int f[N][N];

// int main()
// {
//     cin>>n;
//     for(int i=1;i<=n;i++)
//         for(int j=1;j<=i;j++)
//             cin>>a[i][j];
//     for(int i=0;i<=n;i++)
//         for(int j=0;j<=i+1;j++)
//             f[i][j]=-INf;
//     f[1][1]=a[1][1];
//     for(int i=2;i<=n;i++)
//         for(int j=1;j<=i;j++)
//             f[i][j]=max(f[i-1][j-1]+a[i][j],f[i-1][j]+a[i][j]);
//     int res=-INF;
//     for(int i=1;i<=n;i++)
//         res=max(res,f[n][i]);
//     cout<<res;

// system("pause");
// return 0;
// }



// //最长上升子序列
// #include<iostream> 
// #include<algorithm>
// using namespace std;

// const int N=1010;

// int n;
// int a[N],f[N];//所有以第i个数结尾的上升子序列集合，
//               //值为该集合中所有上升子序列的长度的最大值
// int main()
// {
//     cin>>n;
//     for(int i=1;i<=n;i++)
//     {    
//         f[i]=1;//表示以i结尾的上升子序列长度为1，只有i一个数

//         for(int j=1;j<i;j++)
//             if(a[j]<a[i])
//                 f[i]=max(f[i],f[j]+1);

//     }

// }

// 最长上升子序列II
// #include<iostream>
// #include<algorithm>
// using namespace std;

// const int N=100010;

// int n;
// int a[N];//存每个数
// int q[N];//不同长度的上升子序列结尾数的最小值


// int main()
// {
//     cin>>n;
//     for(int i=0;i<n;i++)
//     {
//        cin>>a[i];
//     }
//     int len=0;//当前最大长度，q中元素个数
//     q[0]=-2e9;//小于所有数
//     for(int i=0;i<n;i++)
//     {
//         int l=0,r=len;
//         while(l<r)//求的数是q[]的[]中的东西
//         {
//             int mid=(l+r+1)/2;
//             if(q[mid]<a[i])
//             //要找的是小于ai的最大值，所以在mid右边
//                 l=mid;
//             else
//                 r=mid-1;
//         }
// //得到的数l；r， 是小于ai的最大值，是q长度为len的结尾最小值
// // 可以接在哪个长度的后面
//         len=max(len,r+1);
// //         //存当前序列长度从1到最长len的情况
// //         //len=4则有1234种长度的序列
// //         q[r+1]=a[i];
// //     }
// //     cout<<len; 
// //     system("pause");
// //     return 0;
// // }



// //最长公共子序列
// #include<iostream>
// #include<string>
// #include<algorithm>
// using namespace std;
// const int N=1010;
// int n,m;
// char a[N],b[N];
// int f[N][N];

// int main()
// {
//     cin>>n>>m;
//     scanf("%s%s",&a+1,&b+1);
//     for(int i=1;i<=n;i++)
//     {
//         for(int j=1;j<=m;j++)
//         {
//             f[i][j]=max(f[i-1][j],f[i][j-1]);
//             if(a[i]==b[j])//第三种情况未必存在
//                 f[i][j]=max(f[i][j],f[i-1][j-1]+1);
//         }
//     }
//     cout<<f[n][m];

// }


// //石子合并
// // p1880
// #include<iostream>
// #include<algorithm>

// using namespace std;

// const int N=105;
// int n;
// int s[N];
// int f[N][N];

// //j-i+1为i到j的长度(含i,j)
// int main()
// {
//     scanf("%d",&n);
//     for(int i=1;i<=n;i++)
//         scanf("%d",s[i]);

//     for(int i=1;i<=n;i++)
//     {
//        s[i]+=s[i-1];
//     }//前缀和

//     for(int len=2;len<=n;len++)
//     //区间长度，从为2的开始
//     {//在该区间长度下，枚举 每段为该区间长度的区间
//         for(int i=1;i+len-1<=n;i++)
//         {
//             int l=i,r=i+len-1;
//             f[l][r]=1e8;
//             for(int k=l;k<r;k++)
//             {
//                 f[l][r]=min(f[l][r],f[l][k]+f[k+1][r]+s[r]-s[l-1]);

//             }
//         }
//     }
//     system("pause");
//     return 0;

// }





// 状压dp
