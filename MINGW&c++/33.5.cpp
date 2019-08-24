#include<iostream>
#include<algorithm>
#include <iomanip>
using namespace std;


struct node
{
    int a,b;
}c[1005];
bool cmp(node x,node y)
{
    return x.a<y.a;
}

int main()
{
    int i,n,m;
    double t=0.0;
    cin>>n;
    m=n;
    c[0].a=0;
    c[0].b=0;
    for(i=1;i<=n;i++)
        {
            cin>>c[i].a;
            c[i].b=i;
        }
    sort(c+0,c+n+1,cmp);
    for(i=1;i<=n;i++)
        cout<<c[i].b<<" ";
    cout<<endl;
    for(i=1;i<n;i++)
    { 
        // cout<<c[i]<<" "<<"zong";
        t+=c[i].a*(m-1);
        m--;
        // cout<<t<<" "<<m<<endl;
    }
    t/=n;
cout<<fixed<<setprecision(2)<<t;
    system("pause");
    return 0;
}