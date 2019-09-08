#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int a[10050],b[10050];
    int  yqj,yqn,i,j,k,cb,n,m=0,price,p,xj,t1,t2,t3,t4,flag=0;
    cin>>yqj;
    cin>>a[0]>>b[0];//chengben,chengbenmaichu
    cb=a[0];
    for(i=1;i<10050;i++)
    {
        cin>>a[i]>>b[i];
        if(a[i]==-1)
            break;
        if(a[i]==yqj)
            yqn=b[i];
        t1=a[i],t2=b[i];
        t3=a[i-1],t4=b[i-1];
        n=t1-t3;
        if(n>1)
        {
            i++;
            a[i]=t1;
            b[i]=t2;
            for(i;n>1;i++)
            {
              n--;
              a[i]=a[i-1]-1;
              b[i]=b[i-1]+(t4-t2)/(t1-t3);
              if(a[i]==yqj)
                yqn=b[i];
            }
        }
        a[i]=t1,b[i]=t2;
    }
    cin>>xj;
        for(j=i;j<10000;j++)
        {
            a[j]=a[j-1]+1;
            b[j]=b[j-1]-xj;
            if(a[j]==yqj)
                yqn=b[j];
            if(b[j]<=0)
                {   
                    break;
                }
        }

price=0;
for(k=1;k<=35;k++)
{
    m=-100;
    for(j=0;b[j]>0;j++)
    {
        n=(a[j]-cb-k)*b[j];
        if(n>m)
        {
            m=n;
            price=a[j];
            p=-1;
        }
    }
    if(price==yqj)
    {
        cout<<k*p;
        system("pause");
        return 0;
    }
    m=-100;
    for(j=0;b[j]>0;j++)
    {
        n=(a[j]-cb+k)*b[j];
        if(n>m)
        {
            m=n;
            price=a[j];
            p=1;
        }
    }
    if(price==yqj)
    {
        cout<<k*p;
        flag=1;
        system("pause");
        return 0;
    }
}
if(flag==0)
    {
        cout<<"NO SOLUTION";
    }
    return 0;
}
