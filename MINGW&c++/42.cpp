//p1002
#include<iostream>
#include<algorithm>
using namespace std;

const int N=30;
long long a[N][N];
long long n,m,mx,my;
int main()
{
    cin>>n>>m>>mx>>my;
    for(int i=0;i<=n;i++)
        for(int j=0;j<=m;j++)
            a[i][j]=1;
    a[mx][my]=0;
    a[mx+2][my-1]=0;
    a[mx+2][my+1]=0;
    a[mx-2][my-1]=0;
    a[mx-2][my+1]=0;
    a[mx-1][my+2]=0;
    a[mx+1][my+2]=0;
    a[mx-1][my-2]=0;
    a[mx+1][my-2]=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            {
                if(a[i][j]!=0)
                    a[i][j]=a[i-1][j]+a[i][j-1];
            }

    cout<<a[n][m];





    system("pause");
    return 0;
}