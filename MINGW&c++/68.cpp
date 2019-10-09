// p1093
#include<iostream>
#include<algorithm>
using namespace std;

const int N=310;
int n;
struct xs
{
    int yu;
    int shu;
    int ying;
    int sum;
    int num;
}stu[N];
int S[N];

bool cmp(xs a,xs b)
{
    if(a.sum!=b.sum)
    {
        return a.sum>b.sum;
    }
    else
    {
        if(a.yu!=b.yu)
        {
            return a.yu>b.yu;
        }
        else
        {
            return a.num<b.num;
        }
    }
    

}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        stu[i].num=i;
        cin>>stu[i].yu>>stu[i].shu>>stu[i].ying;
        stu[i].sum=stu[i].yu+stu[i].shu+stu[i].ying;
    }
    sort(stu+1,stu+n+1,cmp);
    for(int i=1;i<=5;i++)
        cout<<stu[i].num<<' '<<stu[i].sum<<endl;


    system("pause");
    return 0;

}
