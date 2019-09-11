//p1019
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string word[20];
int f[20];
string s,d;
string e;    
int t,flag,tt;
string c;
int num,i,j,k;

int klj(string a,string b)
{

    for(int i=a.size()-1;i>=0;i--)
        if(a[i]==b[0])
        {
            t=i;
            break;
        }
    for(int i=t,j=0;i<=a.size()-1;i++,j++)
    {   
        flag=1;
        if(a[i]!=b[j])
        {
            flag=0;
            break;
        }
    }
    if(flag==1)
    {   
        if(a.substr(0,t)+b!=a&&a.substr(0,t)+b!=b||a.size()==1)
            return flag;
        else
        {
            return 0;
        }
        
    }
    else
        return 0;
    
}

void dfs(string c)
{   
    for(i=0;i<num;i++)
    {   
        if(f[i]>=2||klj(c,word[i])==0||d==e)
            continue;
        if(i==5)
            break;
        d=c;
        cout<<"this d is "<<d<<endl;
        d=c.substr(0,t)+word[i];
        cout<<"this d+c is "<<d<<endl;
        f[i]++;
        dfs(d);
        f[--i]--;
        i=0;
        e=c;
        cout<<"e is"<<e<<endl;
        d=c;
        cout<<"this hsd is "<<d<<endl;   
    }
    
    

}

int main()
{
    cin>>num;
    for(i=0;i<num;i++)
    {
        cin>>word[i];
    }
    cin>>s;
    dfs(s);

    system("pause");
    return 0;
}