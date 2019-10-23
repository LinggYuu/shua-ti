//特指整数离散化
//值域很大，但很稀疏

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
#include<vector>
#include<algorithm>
using namespace std;

const int N=300010;

int n,m;
int a[N],s[N];//a数组为存的数，s数组为前缀和
typedef pair<int,int>PII;

vector<int>alls;//存的是所有要离散化的下标
vector<PII>add,query;//插入 , 求

//离散化
int find(int x)//alls已经从小到大
{
    int l=0,r=alls.size()-1;
    while(l<r)
    {
        int mid=l+r>>1;
        if(alls[mid]>=x)//大于等于x的最小值
            r=mid;
        else
        {
            l=mid+1;
        }
        
    }
    return r+1;
}

int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        int x,c;
        cin>>x>>c;
        add.push_back({x,c});//下标x的点加c
        alls.push_back(x);//记录下标x，要被离散化
    }
    for(int i=0;i<=m;i++)
    {   
        int l,r;
        cin>>l>>r;
        query.push_back({l,r});
        alls.push_back(l);//需离散的下标
        alls.push_back(r);//需离散的下标
    }
    //去重
    sort(alls.begin(),alls.end());
    //把坐标从小到大排序
    alls.erase(unique(alls.begin(),alls.end()),alls.end());
    // 有一个alls长度 的数组 存 
    //处理插入
    for(auto item:add)//遍历add中的每个PII
    {
        int x=find(item.first);
        //将add数组中的下标映射到数组中的位置x
        a[x]+=item.second;
    }
    //预处理前缀和
    for(int i=1;i<=alls.size();i++)
    {
        s[i]=s[i-1]+a[i];
    }
    //处理询问
    for(auto item:query)
    {
        int l=find(item.first),r=find(item.second);
        cout<<s[r]-s[l-1]<<endl;
    }

    return 1l;
}