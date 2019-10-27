#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=1000010,M=1000010;

char s1[N],s2[N];
int ne[N];
int n,m;
int main()
{
    cin>>s1+1>>s2+1;
    n=strlen(s1+1);
    m=strlen(s2+1);

    for(int i=2,j=0;i<=m;i++)
    {
        while(j&&s2[i]!=s2[j+1])
            j=ne[j];
        if(s2[i]==s2[j+1])
            j++;
        ne[i]=j;
    }

    for(int i=1,j=0;i<=n;i++)
    {
        while(j&&s1[i]!=s2[j+1])
            j=ne[j];
        if(s1[i]==s2[j+1])
            j++;
        if(j==m)
        {
            cout<<i-m+1<<endl;
            j=ne[j];
        }
    }
    for(int i=1;i<=m;i++)
        cout<<ne[i]<<' ';
    cout<<endl;
    
    system("pause");
    return 0;
}