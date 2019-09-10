//p1019
#include<iostream>
#include<string>
using namespace std;
string word[20];
int f[20];
string s;
string e,d;
int num,i,j,k;

string lj(string a,string b)
{
    int t,flag;
    string c;
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
            return c=a.substr(0,t)+b;
        else
        {
            return "0";
        }
        
    }
    else
        return "0";
    
}

void dfs(int n,string c)
{
    if(n==7)
    {
        cout<<c.size()<<endl;
        return;
    }
    for(i=0;i<num;i++)
    {
        if((lj(c,word[i])!="0")&&f[i]<2&&(lj(c,word[i])!=e))
        {   
            int t,g;
            d=c;        
            cout<<d<<" is d"<<endl;
            c=lj(c,word[i]);
            e=c;
            f[i]++;
            t=i;
            cout<<c<<" is c"<<endl;
            dfs(n+1,c);   
            c=d;
            cout<<c<<" huisuhouis c"<<endl;
            f[t]--;
            i=0; 
            
        }
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
    dfs(0,s);

    system("pause");
    return 0;
}