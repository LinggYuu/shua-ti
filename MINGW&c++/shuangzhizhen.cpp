// //模板
// for(i=0,j=0;i<n;i++)
// {
//     while(j<i&&check(i,j))
//         j++;
//     //每道题具体逻辑
// }
// // 可用于优化，朴素算法优化到O(n)

// // 输出单词
// // abc def ghi将其输出每个一行
// #include<iostream>
// #include<string.h>
// using namespace std;

// int main()
// {
//     char str[1000];
//     gets(str);
//     int n=strlen(str);
//     for(int i=0;i<n;i++)
//     {
//         int j=i;
//         while(j<n&&str[j]!=' ')
//             j++;
//         //该题具体逻辑
//         for(int k=i;k<j;k++)
//             cout<<str[i];
//         cout<<endl;
//         i=j;
//     }

//     return 0;
// }
// //最长连续无重复子序列
// for(int i=0;i<n;i++)
// {
//     for(int j=0;j<=i;j++)
//     {
//         if(check(j,i))
//         {
//             res=max(res, i-j+1);
//         }
//     }
// }//朴素

// //1 2 2 3 5
// //2 3 5
// for(int i=0;j=0;i<n;i++)
// {
//     while(j<=i&&check(j,i))
//     //j到i有重复元素;a[i]!=a[j]
//         j++;
//     res=max(res,i-j+1);
// }
// // 开数组动态记录数出现次数
// // S[N]
// // S[a[i]]++
// #include<iostream>
// using namespace std;
// const int N=100010;

// int n;
// int a[N],s[N];//s计数器

// int main()
// {
//     cin>>n;
//     for(int i=0;i<n;i++)
//         cin>>a[i];
//         int res=0;
//         for(int i=0,j=0;i<n;i++)
//         {
//             s[a[i]]++;
//             while(j<=i&&s[a[i]]>1)
//             {
//                 s[a[j]]--;
//                 j++; 
//             }
//             res=max(res,i-j+1);
//         }
//     cout<<res<<endl;

// }
