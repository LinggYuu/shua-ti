#include<iostream>
#include<cstdlib>
using namespace std;
int main()
{
    int n,num[100],t,s=0;
    int i,j=0;
    cin>>n;
    
    for(int i=0;i<n;i++)
        cin>>num[i];
    

    for(int j=n-1;j>0;j--)
        for(int i=0;i<j;i++)
            if(num[i]>num[i+1])
                {
                  t=num[i];
                  num[i]=num[i+1];
                  num[i+1]=t;  
                }
            else if(num[i]==num[i+1])
                {
                    num[i]=0;
                }



    for(i=0;i<n;i++)
        if(num[i]!=0)
            {
                s++;
            }
    cout<<s<<endl;
    for(i=0;i<n;i++)
        if(num[i]!=0)
            cout<<num[i]<<" ";






    system("pause");
    return 0;
}