#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n,t=0,te=0;
    int i;
    int a[10000];
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];

    sort(a,a+n);//a+n为从a开始第n个数据 ，a+1为从啊开始第1个数据

    for(i=1;i<n;i++)
    {   
        a[i]+=a[i-1];
        te+=a[i];
        sort(a+i,a+n);
    }
        
    cout<<te<<endl;

    system("pause");
    return 0;
}