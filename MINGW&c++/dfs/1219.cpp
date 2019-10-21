// #include<iostream>
// using namespace std;

// int n;
// int x[15];
// int y[15];
// int a[30];
// int b[30];
// int sum;
// void dfs(int i)
// {
//     if(i>n)
//         return;
//     for(int j=1;j<=n;j++)
//     {
//         if(y[j]==0&&a[i+j]==0&&b[j-i+n]==0)
//         {
//             x[i]=j;
//             y[j]=1;
//             a[j+i]=1;
//             b[j-i+n]=1;
//             if(i==n)
//             {
//                 sum++;
//                 if(sum<=3)
//                 {
//                     for(int k=1;k<=n;k++)
//                     cout<<x[k]<<" ";
//                     cout<<endl;
//                 }
//             }
//             dfs(i+1);
//             y[j]=0;
//             a[i+j]=0;
//             b[j-i+n]=0;
//         }
//     }

// }

// int main()
// {
//     cin>>n;
//     dfs(1);
//     cout<<sum<<endl;
//     system("pause");
//     return 0;
// }
#include<iostream>
using namespace std;

const int N=15;
int r[N],c[N],l1[N*N],l2[N*N];
int n,sum;
int st[N*N];
void dfs(int i)
{
    if(i>n)
        return;
    for(int j=1;j<=n;j++)
    {
        if(c[j]==0&&l1[i+j]==0&&l2[j-i+n]==0)
        {
            st[i]=j;
            c[j]=1;
            l1[j+i]=1;
            l2[j-i+n]=1;
            if(i==n)
            {
                sum++;
                if(sum<=3)
                {
                    for(int k=1;k<=n;k++)
                    cout<<st[k]<<" ";
                    cout<<endl;
                }
            }
            dfs(i+1);
            c[j]=0;
            l1[i+j]=0;
            l2[j-i+n]=0;
        }
    }
}
int main()
{
    cin>>n;
    dfs(1);
    cout<<sum<<endl;
    system("pause");
    return 0;
}


// conclusion:

//     对角线范围注意
//     从第一行开始枚举
//     可以的话dfs下一行
//     同时记录数组st记录当前行的j
// dfs(i+1)绝对不能用dfs(i++)，错的