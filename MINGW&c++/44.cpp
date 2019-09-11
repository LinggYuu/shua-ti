//p1019
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string word[20];
int f[20];
string s,d;
int ml[20];  
int t;

int num,i,j,len=0;

bool ch(string a,string b)
{
    bool fl=0;

    for(int i=a.size()-1;i>=0;i--)
        if(a[i]==b[0])
        {
            t=i;
            fl=1;
            break;
        }
    if(fl==0)
        return 0;
    for(int i=t,j=0;i<=a.size()-1;i++,j++)
    {   
        if(a[i]!=b[j])
        {
            fl=0;
            return 0;
        }
    }
 
    if((a.substr(0,t)+b!=a&&a.substr(0,t)+b!=b)||(a.size()==1))
        return 1;
    else
    {
        return 0;
    }

    
}

void dfs(string c)
{   
    bool p=0;
    for(int k=0;k<num;k++)
    {
        d=c;
        // cout<<"0d is "<<d<<endl;
        if(ch(d,word[k])==0||f[k]>=2)
            continue;
        d=c.substr(0,t)+word[k];
        // cout<<"1d is "<<d<<endl;
        p=1;
        f[k]++;
        dfs(d);
        f[k]--;
        d=c;
        // cout<<d<<endl;
    }
    if(p==0)
    {
        // cout<<"final d is"<<d<<endl;
        int dd=d.size();
        len=max(len,dd);
        // cout<<len<<endl;
        return;
    }
    

}

int main()
{

    cin>>num;
    for(i=0;i<num;i++)
    {
        cin>>word[i];
    }
    i=0;
    cin>>s;
    for(i=0;i<num;i++)
    {   
        if(ch(s,word[i]))
        {   
            len=word[i].size();
            ml[i]=len;
            f[i]++;
            dfs(word[i]);
            if(ml[i]<len)
                ml[i]=len;
        }
    }
    int max=0;
    for(i=0;i<num;i++)
    {
        if(ml[i]>max)
        max=ml[i];
    }
    cout<<max;
    system("pause");
    return 0;
}