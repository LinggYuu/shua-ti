#include<iostream>
using namespace std;

int n;
int x[15];
int y[15];
int a[30];
int b[30];
int sum;
void dfs(int i)
{
    if(i>n)
        return;
    for(int j=1;j<=n;j++)
    {
        if(y[j]==0&&a[i+j]==0&&b[j-i+n]==0)
        {
            x[i]=j;
            y[j]=1;
            a[j+i]=1;
            b[j-i+n]=1;
            if(i==n)
            {
                sum++;
                if(sum<=3)
                {
                    for(int k=1;k<=n;k++)
                    cout<<x[k]<<" ";
                    cout<<endl;
                }
            }
            dfs(i+1);
            y[j]=0;
            a[i+j]=0;
            b[j-i+n]=0;
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

//      void queen(int row)

//     {

//               if (n == row)      //如果已经找到结果，则打印结果

//                     print_result();

//               else {

//                           for (k=0 to N) { //试探第row行每一个列

//                                   if (can_place(row, k) { 

//                                           place(row, k);   //放置皇后

//                                          queen(row + 1);  //继续探测下一行

//                                   }

//                          }

//              }

//     }
// ————————————————
// 版权声明：本文为CSDN博主「hackbuteer1」的原创文章，遵循 CC 4.0 BY-SA 版权协议，转载请附上原文出处链接及本声明。
// 原文链接：https://blog.csdn.net/Hackbuteer1/article/details/6657109