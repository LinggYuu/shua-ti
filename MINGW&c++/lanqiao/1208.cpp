#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=105;
char q[N],p[N];
int len;

void c(int x)
{
    if(q[x]=='*')
        q[x]='o';
    else if(q[x]=='o')
        q[x]='*';
    if(q[x+1]=='*')
        q[x+1]='o';
    else if(q[x+1]=='o')
        q[x+1]='*';

}

int main()
{
    cin>>q;
    cin>>p;
    len=strlen(q);
    int step=0;
    for(int i=0;i<len-1;i++)
    {
        if(q[i]!=p[i])
        {
            step++;
            c(i);
        }
    }
    if(q[len-1]==p[len-1])
        cout<<step<<endl;

    system("pause");
    return 0;
}