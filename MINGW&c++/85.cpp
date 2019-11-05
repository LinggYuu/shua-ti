// p1115
#include<iostream>
using namespace std;

const int N=200010;

int num[N];
int s[N];
int n;

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        cin>>num[i];
    }

    for(int i=1;i<=n;i++)
        {
            s[i]=num[i];
            if(s[i-1]+num[i]>s[i])
                s[i]=s[i-1]+num[i];
            
        }
    int ma=-0x3f3f;
    for(int i=1;i<=n;i++)
    {
        if(ma<s[i])
            ma=s[i];
    }
    cout<<ma;




    system("pause");
    return 0;
}