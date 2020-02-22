#include<iostream>
using namespace std;

int N=50;
int f[50];
int n;

int main()
{
    f[1]=0,f[2]=1;
    cin>>n;

    for(int i=3;i<=n;i++)
    {
        f[i]=f[i-1]+f[i-2];
    }
    for(int j=1;j<=n;j++)
        cout<<f[j]<<' ';
    system("pause");
    return 0;

}