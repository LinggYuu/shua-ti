#include<iostream>
using namespace std;

int main()
{

int n,k,i,j;
cin>>n>>k;

long f[100002]={0};
f[0]=f[1]=1;
for(i=2;i<=n;i++)
{
    if(k==1)
        {
            f[i]=1;
            continue;
        }
    if(i<=k)
        {
            f[i]=f[i-1]*2;
            f[i]%=100003;
        }
    else
        for(j=i-k;j<=i-1;j++)
            {
                f[i]+=f[j];
                f[i]%=100003;
            }
            //for(j=1;j<=k;j++)
            //  f[i]+=f[i-j];
}
    cout<<f[n];


    system("pause");
    return 0;
}