// p1098
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
//'-':45
int p1,p2,p3;
string a,ans[100];
int line[55];
int t=1,tt=1;

void create(char a,char b,int idx)
{

    if(a>b||(a<=57&&a>=48)&&(b<=122&&b>=97))//st0
    {
        ans[idx]='-';
        // cout<<"bubian "<<endl;
        return;
    }
    else if(b-a==1)//st5.1
    {
        ans[idx]="";
        return;
    }
    else if(b==a)
    {
        ans[idx]="-";
        return;
    }
    else if((a>=97&&a<=122)&&(b>=97&&b<=122))
    {
        char x;
        if(p3==1)
        {
            for(char i=a+1;i<=b-1;i++)
            {   

            for(int j=0;j<p2;j++)
            {
                x=i;
                if(p1==2)
                {
                    x=i-32;
                }
                else if(p1==3)
                {
                    x='*';
                }
                ans[idx]=ans[idx]+x;
            }
            }
        }
        else if(p3==2)
        {
            for(char i=b-1;i>=a+1;i--)
            {   
                for(int j=0;j<p2;j++)
                {
                    x=i;
                    if(p1==2)
                    {
                        x=i-32;
                    }
                    else if(p1==3)
                    {
                    x='*';
                    }
                    ans[idx]=ans[idx]+x;
                }
            }

        }    
        return;
    }
    else if(a>=48&&a<=57&&b>=48&&b<=57)
    {
        char x;
        if(p3==1)
        {
            for(char i=a+1;i<=b-1;i++)
                for(int j=0;j<p2;j++)
                {
                    x=i;
                    if(p1==3)
                    {
                        x='*';
                    }
                    ans[idx]=ans[idx]+x;
                }
        }
        else if(p3==2)
        {
            for(char i=b-1;i>=a+1;i--)
                for(int j=0;j<p2;j++)
                {
                    x=i;
                    if(p1==3)
                    {
                        x='*';
                    }
                    ans[idx]=ans[idx]+x;
                }
        }
        return;
    }
    else 
    {
        ans[idx]='-';
    }
}



int main()
{
    cin>>p1>>p2>>p3;
    cin>>a;
    for(int i=0;i<a.size();i++)
        if(a[i]=='-'&&i>0)
        {
            line[t++]=i;
        }

    for(int i=1;i<t;i++)
    {
        create((a[line[i]-1]),(a[line[i]+1]),line[i]);
    }
    for(int i=0,k=1;i<a.size();i++)
    {
        if(a[i]=='-'&&i>0)
        {
            cout<<ans[line[k++]];
            continue;
        }
        cout<<a[i];
    }   



    system("pause");
    return 0;

}