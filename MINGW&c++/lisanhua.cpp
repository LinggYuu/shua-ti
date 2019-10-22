//特指整数离散化

// a有序
// a[] 1 3 100 200 5000
//     0 1  2   3    4
// 映射到下标

// a[]中可能有重复元素,去重

// 如何算出x离散化后的值 二分

// 去重:
// vector<int>alls;
// sort(alls.begin(),alls.end());
// alls.erase(unique(alls.begin(),alls.end()),alls.end());
// // unique将重复的元素移到最后，并返回位置
// // 【————————————————】
// // 【————————|-------】
// //去掉重复元素

// // 二分求出x对应的离散化的值
// int find(int x)//找到第一个大于等于x的位置
// {
//     int l=0,r=alls.size()-1;
//     while(l<r)
//     {
//         int mid=l+r>>1;
//         if(alls[mid]>=x)
//             r=mid;
//         else
//         {
//             l=mid+1;
//         }
//     return r+1;//+1的话映射到1，2，3.....
//     }
// }



//区间和
#include<iostream>
using namespace std;
1：46