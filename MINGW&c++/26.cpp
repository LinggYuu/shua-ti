#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    int i,j,num,n[100];
    char a[100][6];
    cin>>num;
    for(i=0;i<=num;i++)
        {cin>>n[i];
            if(i==num-1)
                sprintf (a[i],"x");
           else       
                sprintf (a[i],"x^%d",num-i);
        }
    for(i=0;i<=num;i++)
    {
        if(i==0)
        {
            if(n[i]==0)
                continue;

            else if(n[i]>0)
            {
                if(n[i]==1)
                    cout<<a[i];
                else
                    cout<<n[i]<<a[i];        
            }
            else
            {
                if(n[i]==-1)
                    cout<<"-"<<a[i];
                else
                    cout<<n[i]<<a[i];
            }
        }
        else if(i==num)
        {
            if(n[i]==0)
                continue;
            else  if(n[i]>0)
                cout<<"+"<<n[i];
            else 
                cout<<n[i];
        }
        else
        {
            if(n[i]==0)
                continue;
            else if(n[i]>0)
            {
                if(n[i]==1)
                    cout<<"+"<<a[i];
                else
                    cout<<"+"<<n[i]<<a[i];
            }
            else
            {
                if(n[i]==-1)
                    cout<<"-"<<a[i];
                else
                    cout<<n[i]<<a[i];
            }
            
        }
        
    }
        
    system("pause");
    return 0;
}