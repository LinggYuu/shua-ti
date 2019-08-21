#include<iostream>
using namespace std;
void swap(int &a,int &b)
{
    int t=a;
    a=b;
    b=t;
}
void qs(int s[],int l,int r)
{
    int i=l,j=r;
    int x=s[(l+r)/2];
    do
    {
        while(s[j]>x)
            j--;
        while(s[i]<x)
            i++;
        if(i<=j)
            swap(s[i++],s[j--]);
    }while(i<=j);
    if(i<r)
        qs(s,i,r);
    if(j>l)
        qs(s,l,j);
}
int main(){

    int a[100100];
    int N,i;
    cin>>N;
    for(i=0;i<N;i++)
        cin>>a[i];
    qs(a,0,N-1);
    for(i=0;i<N;i++)
        cout<<a[i]<<" ";
    system("pause");
    return 0;
}