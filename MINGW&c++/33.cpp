#include<iostream>
#include<algorithm>
#include <iomanip>

using namespace std;


int main()
{
    int n,m,i;
    int c[1005][2];
    cin>>n;
    m=n;
    double t=0.0;
    c[0][0]=0;
    for(i=1;i<=n;i++)
        {
            cin>>c[i][0];
            c[i][1]=1;
        }
    // sort(c[]+0,c+n+1);
    for(i=1;i<=n;i++)
    {
        cout<<c[i][0];
    }
    cout<<endl;
//     for(i=1;i<n;i++)
//     { 
//         // cout<<c[i]<<" "<<"zong";
//         t+=c[i]*(m-1);
//         m--;
//         // cout<<t<<" "<<m<<endl;
//     }
//     t/=n;
// cout<<fixed<<setprecision(2)<<t;
system("pause");
return 0;



}