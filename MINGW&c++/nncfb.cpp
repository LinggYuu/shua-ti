#include<iostream>
#include<algorithm>
using namespace std;
void cfb(int n)
{
for(int i=1;i<=n;i++)
{   
    for(int j=1;j<=i;j++)
        cout<<i<<'*'<<j<<'='<<i*j<<' ';
    cout<<endl;
    
}
}
int main()
{
    int a;
    cin>>a;
    cfb(a);
    system("pause");
    return 0;
}