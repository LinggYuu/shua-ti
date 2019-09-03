#include<iostream>
using namespace std;

int main()
{
    long long num[100010];
    long long sum[100010];
    long long a,b,d=0;
    cin>>a>>b;
    for(int i=1;i<=a;i++)
        cin>>num[i];
    for(int i=1;i<=a;i++)
        sum[i]=sum[i-1]+num[i];
    while(a-b>=0)
        {   d+=sum[a]-sum[a-b];
            a--;
        }
    cout<<d;

    system("pause");
    return 0;
}