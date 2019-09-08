#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
    int ep,epn;
    int fc,xj,i,j,n=0,m=0;
    int a[100000],b[100000],c[100000],e[10000],f[10000],l[100000],d[2];
    cin>>ep;
    cin>>a[0]>>b[0];
    fc=a[0];
    for(i=0;i<100000;i++)
        {
            cin>>a[i]>>b[i];
            a[i]-=fc;
            if(a[i]==ep-fc)
                epn=b[i];
            if(b[i]==-1)
                    break;
        }

    cin>>xj;    
    d[0]=a[i-1];
    d[1]=b[i-1];
    if(ep-fc<a[i-1])
        {
            for(int j=i;a[j]>=a[i-2];j++)
            {
                a[j]=d[0]-1;
                b[j]=d[1]-10;
            }
        }
    a[j-1]=a[i-1];
    b[j-1]=b[i-1];
    for(j=i;j<10000;j++)
        {
            a[j]=a[j-1]+1;
            b[j]=b[j-1]-xj;
            if(a[j]==ep-fc)
                epn=b[j];
            if(b[j]<=0)
                {   
                    j--;
                    break;
                }
        }
for(j=0;b[j]>=0;j++)
    n++;
for(int k=-fc;k<=fc;k++)
{   
    for(j=0;j<n;j++)
        {   
            l[j]=(a[j]+k)*b[j];
        }
    sort(l,l+n);
    if((ep-fc+k)*epn==l[j-1])
        {   
            c[m++]=k;
        }
}
    if(m==0)
        {
            cout<<"NO SOLUTION";
            return 0;
        }
    for(int i=0;i<m;i++)
        {
            l[i]=c[i];
            c[i]=abs(c[i]);
        }
    sort(c,c+m);
    for(int i=0;i<m;i++)
        if(abs(l[i])==c[0])
            cout<<l[i];
    
    
    system("pause");
    return 0;
}