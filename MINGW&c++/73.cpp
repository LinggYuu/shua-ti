// p5587
#include<iostream>
#include<string>
#include<math.h>
#include<algorithm>
#include <iomanip>
using namespace std;

const int hang=10100,T=10100,N=1000010;

string h1[hang],h2[hang];
int n,m,nn;
double t,cnt;


int main()
{
    while(1)
    {
        getline(cin,h1[n]);
        if(h1[n++]=="EOF")
        {
            n--;
            h1[n].erase();
            break;
        }
    }
    // cout<<"n:"<<n<<endl<<endl;
    n=0;
    while(1)
    {
        getline(cin,h2[n]);
        if(h2[n++]=="EOF")
        {

            n--;
            h2[n].erase();
            // cout<<"h2end"<<endl;
            break;
        }
    }
    // cout<<"n:"<<n<<endl<<endl;
    cin>>t;

    for(int i=0;i<n;i++)
    {
        int ss=h1[i].size();
        for(int j=0;j<h1[i].size();j++)
        {
            if(h1[i][j]=='<')
            {
                string a,b;
                if(j==0)
                    {
                        b=h1[i].substr(j+1);
                        j-=1;
                    }
                else if(j==h1[i].size()-1)
                    {
                        a=h1[i].substr(0,j-1);   
                        j-=1;
                    }
                else
                {
                    a=h1[i].substr(0,j-1);
                    // cout<<a<<endl;
                    b=h1[i].substr(j+1);
                    // cout<<b<<endl;
                    j-=2;
                }
             
                // cout<<a+b<<endl;
                h1[i]=a+b;
                // cout<<h2[i]<<endl;
                ss=(a+b).size();
                // cout<<ss<<endl;
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        int ss=h2[i].size();
        // cout<<ss<<endl;
        for(int j=0;j<ss;j++)
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
                    // cout<<a<<endl;
                    b=h2[i].substr(j+1);
                    // cout<<b<<endl;
                    j-=2;
                }
             
                // cout<<a+b<<endl;
                h2[i]=a+b;
                // cout<<h2[i]<<endl;
                ss=(a+b).size();
                // cout<<ss<<endl;
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
    // for(int i=0;i<n;i++)
    // {
    //     cout<<"h1"<<i<<"is:"<<h1[i]<<endl;
    //     cout<<"h2"<<i<<"is:"<<h2[i]<<endl;
    // }
 
    cnt*=60;
    cout<<round((double)cnt/(double)t);
    system("pause");
    return 0;
}

