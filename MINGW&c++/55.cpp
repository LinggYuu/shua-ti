//R24218161
#include<iostream>
#include<string>
using namespace std;
int st[50];//17-42
char ma[100][26];
void getnum(string x)
{
    for(int i=0;i<x.size();i++)
    {
        if((x[i]-'0'-17>25)||(x[i]-'0'-17<0))
            continue;
        st[x[i]-'0'-17]+=1;
    }
    return;
}

int main()
{   
    int max=0;
    int i=0;
    string a,b,c,d;
    getline(cin,a);
    getline(cin,b);
    getline(cin,c);
    getline(cin,d);
    getnum(a);
    getnum(b);
    getnum(c);
    getnum(d);
    for(int i=0;i<26;i++)
    {   
        // cout<<st[i]<<endl;
        if(st[i]>max)
            max=st[i];
    }
    int mm=max;
    for(int i=0;i<max;i++)
    {
        for(int j=0;j<26;j++)
        {
            if(st[j]==mm)
            {
                st[j]--;
                ma[i][j]='*';
            }
            else
                ma[i][j]=' ';
        }
        mm--;
        // cout<<endl;
    }
    char zf='A';
    for(int i=0;i<26;i++)
    {   
        ma[max][i]=zf;
        zf++;
    }
    for(int i=0;i<=max;i++)
    {   
        int flag=1;
        for(int j=0;j<26;j++)
        {
            if(ma[i][j]=='*')
            {
                for(int k=j+1;k<26;k++)
                {
                    if(ma[i][k]=='*')
                    flag=0;
                }
                if(flag==1)
                {
                    cout<<ma[i][j];
                    break;
                }
                cout<<ma[i][j]<<' ';
                flag=1;
            }
        else if(ma[i][j]=='Z')
            cout<<ma[i][j];
        else
            cout<<ma[i][j]<<' ';    
        }
        cout<<endl;
    }



    system("pause");
    return 0;
}