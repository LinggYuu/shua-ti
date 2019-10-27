#include<iostream>
#include<algorithm>
using namespace std;

const int N=2010;
int n;
int a[N],w[N];
int f[N][N];//选择前i种美食

int main()
{
    cin.tie();
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        w[i]=1;
    }

    for(int i=1;i<=n;i++)
    { 
        for(int j=1;j<=n;j++)
        {
           f[i][j]=f[i-1][j];
           
           f[i][j]=max(f[i][j],f[i-1][j]+a[i]);

        }
    }
    cout<<f[n][n];
    system("pause");
    return 0;
}