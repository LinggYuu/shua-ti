// p1071
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
using namespace std;


const int N=150;

map<char,char>dic;//65-90
int st[100];
string info,key,task;
int main()
{
    cin>>info;
    cin>>key;
    cin>>task;
    for(int i='A';i<='Z';i++)
    {
        dic[i]='0';
    }
    for(int i=0;i<info.size();i++)
    {
        st[info[i]]=1;
    }
    for(int i=0;i<key.size();i++)
    {
        st[key[i]]=2;
        if(dic[info[i]]<=90&&dic[info[i]]>=65&&dic[info[i]]!=key[i])
        {    
            cout<<"yuanlaishi "<<dic[info[i]]<<endl;
            cout<<"Failed";
            system("pause");
            return 0;
        } 
        dic[info[i]]=key[i];
        for(int i='A';i<='Z';i++)
        {
            if(dic[i]>=65&&dic[i]<=90)
                break;
        }    
    }
    for(int i=0;i<info.size();i++)
    {
        if(dic[info[i]]=='0')
        {
            cout<<"Failed";
            system("pause");
            return 0;
        }
    }
    for(int i='A';i<='Z';i++)
    {
        if(st[i]!=2)
        {
            cout<<"Failed";
            system("pause");
            return 0;
        }
    }
    for(int i=0;i<task.size();i++)
    {
        cout<<dic[task[i]];
    }

    system("pause");
    return 0;
}