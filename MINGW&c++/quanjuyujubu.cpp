#include<iostream>
using namespace std;

static int n;

void jj(int a)
{

    n=a;
    cout<<n<<endl;
}
int main()
{
    int n=0;
    int a;
    cin>>a;
    jj(a);
    cout<<n;
    cin>>n;
    cout<<n;
    system("pause");
    return 0;
}