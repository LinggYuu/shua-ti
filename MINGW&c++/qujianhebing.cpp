//区间合并
//贪心思想
//1.按区间的左端点排序
//2.    


#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

typedef pair<int,int>PII;

const int N=100010;

int n;
vector<PII>segs;

void merge(vector<PII> &segs)
{
    vector<PII>res;//存合并后结果       
    sort(segs.begin(),segs.end());
    //优先以左端点再以右端点排序
    int st=-2e9,ed=-2e9;//村当前线段的st，ed
    for(auto seg:segs)//从前扫描所有线段
    {
        if(ed<seg.first)
        {
            if(st!=-2e9)
                res.push_back({st,ed});
            st=seg.first,ed=seg.second;
        }            
        else//有交点
        {
            ed= max(ed,seg.second);
        }
    }
    if(st!=-2e9)
    {
        res.push_back({st,ed});
    }
    segs=res;
    

}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int l,r;
        cin>>l>>r;
        segs.push_back({l,r});

    }
    merge(segs);
    cout<<segs.size()<<endl;
}


