#include<iostream>
#include<string>
#include<cstring>
using namespace std;

const int N=50;
int n;
string s[N];

void fr(string a)
{
    if(a[0]=='*'||!a[0])
        return;
    cout<<a[0];
    a.erase(0,1);
    for(int i=1;i<=n;i++)
    {
        if(s[i][0]==a[0])
        {
            fr(s[i]);
        }
    }
    a.erase(0,1);
    {
    for(int i=1;i<=n;i++)
    {
        if(s[i][0]==a[0])
        {
            fr(s[i]);
        }
    }
    }

}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
    }
    fr(s[1]);
    system("pause");
    return 0;
}