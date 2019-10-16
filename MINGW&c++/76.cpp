// 1091
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
const int N=110*110*110;
int stu[N],st[N];
int n;
int f[N],ff[N];
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>stu[i];
    }

    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=k;i++)
        {
            f[i]=1;
            for(int j=1;j<i;j++)
            {
                if(stu[j]<stu[i])
                {
                    f[i]=max(f[i],f[j]+1);
                }
            }
        }
        cout<<"f"<<f[k]<<endl;
        for(int i=n;i>=k;i--)
        {
            ff[i]=1;
            for(int j=n;j>i;j--)
            {
                if(stu[j]<stu[i])
                {
                    ff[i]=max(ff[i],ff[j]+1);
                }
            }
        }
        // cout<<"ff"<<k<<":"<<ff[k]<<endl;
        st[k]=f[k]+ff[k];
        st[k]-=1;
        // cout<<st[k]<<endl;
    }
    int ma=-1e8;
    // cout<<endl<<endl;
    for(int i=1;i<=n;i++)
    {
        ma=max(st[i],ma);
        // cout<<st[i]<<endl;
    }
    cout<<n-ma;
    system("pause");
    return 0;
}