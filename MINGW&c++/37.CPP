#include<iostream>
#include<math.h>
using namespace std;
int isprime(int a)
{
    for(int i=2;i<a;i++)
        if(a%i==0)
            return 0;
    return 1;
}
int main()
{
    int n;
    int i,j=0;
    cin>>n;
    for(i=2;i<=sqrt(n);i++)
    {    
        if(n%i==0)
            cout<<(i>n/i?i:n/i);

    }
    


    system("pause");
    return 0;
}