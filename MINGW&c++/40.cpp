//R23609725
#include<iostream>
#include<iomanip>
using namespace std;


// double  fib(int a)
// {
//     if(a<=2)
//         return 1.00;
//     return fib(a-1)+fib(a-2);

// }会超时

int main()
{
    int n,i;
    cin>>n;
    long a[100000];
    a[1]=a[2]=1;
    for(i=3;i<=n;i++)
    {
        a[i]=a[i-1]+a[i-2];
    }
    
    cout<<setiosflags(ios::fixed)<<setprecision(2)<<double(a[n])<<endl;
    system("pause");
    return 0;
}