//归并排序
#include<iostream>
using namespace std;

const int n=1000010;
int a[n],tmp[n];

void ms(int a[],int l,int r)
{
    if(l>=r)
        return;
    int mid=(l+r)/2;
    ms(a,l,mid);
    ms(a,mid+1,r);
    int k= 0,i= l,j=mid+1;
    while(i<=mid&&j<=r)
        if(a[i]<=a[j])  tmp[k++]=a[i++];
        else    tmp[k++]=a[j++];
    while(i<=mid)tmp[k++]=a[i++];
    while(j<=r) tmp[k++]=a[j++];
    for(i=l,j=0;i<=r;i++,j++)
        a[i]=tmp[j];

}
int main()
{
    int a[5]={2, 6, 8, 4, 3};
    ms(a,0,4);
    for(int i=0;i<5;i++)
        cout<<a[i]<<endl;
    system("pause");
}


void ms(int q[],int l,int r)
{
    if(l>=r)
        return;
    int mid=l+r>>1;
    ms(q,l,mid);
    ms(q,mid+1,r);
    int i=l,j=mid+1,k=0;
    while(i<mid&&j<r)
    {
        if(q[i]<q[j])
            tmp[k++]=q[i++];
        else
            tmp[k++]=q[j++];
    }
    while(i<mid)
        tmp[k++]=q[i++];
    while(j<r)
        tmp[k++]=q[j++];
    for(i=l,j=0;i<=r;i++)
        q[i]=tmp[j++];
}