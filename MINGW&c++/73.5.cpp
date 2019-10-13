// T99368
#include<iostream>
#include<string>
#include<math.h>
#include<algorithm>
using namespace std;

const int hang=1010,T=1010,N=100010;

string h1[hang],h2[hang];
int n,m,nn;
double t,cnt;

int main()
{
    while(1)
    {
        getline(cin,h1[n]);
        if(h1[n].empty())
            continue;
        if(h1[n++]=="EOF")
        {
            n--;
            break;
        }
    }
    n=0;
    while(1)
    {
        getline(cin,h2[n]);
        if(h2[n].empty())
            continue;
        if(h2[n++]=="EOF")
        {
            n--;
            break;
        }
    }
    cin>>t;
    t/=60;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<h2[i].size();j++)
        {
            if(h2[i][j]=='<')
            {
                string a,b;
                if(j==0)
                {    
                    b=h2[i].substr(j+1);
                    j-=1;
                }
                else if(j==h2[i].size()-1)
                {
                    a=h2[i].substr(0,j-1);
                    j-=1;
                }
                else
                {
                    a=h2[i].substr(0,j-1);
                    b=h2[i].substr(j+1);
                    j-=1;
                }
                h2[i].erase(0);
                h2[i]+=a;
                h2[i]+=b;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<min(h1[i].size(),h2[i].size());j++)
        {
            if(h1[i][j]==h2[i][j])
            {
                cnt++;
            }
        }
    }

    cnt=(cnt/t);
    cout<<round(cnt);

    system("pause");
    return 0;
}

