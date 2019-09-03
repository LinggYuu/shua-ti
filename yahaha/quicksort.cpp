#include<iostream>
using namespace std;

void qs(int q[],int l,int r)
{
    if(l>=r)
        return;
    int x=q[l+r>>1];
    int i=l-1,j=r+1;
    while(i<j)
    {
        while(q[++i]<x);
        while(q[--j]>x);
        if(i<j)
            swap(q[i],q[j]);
    }
    qs(q,l,j);
    qs(q,j+1,r);

}

void qs(int q[],int l,int r)
{
    if(l>=r)
        return;
    int x=q[l+r>>1];
    int i=l-1;
    int j=r+1;
    while(q[++i]<x);
    while(q[--j]>x);
    if(i<j)
        swap(q[i],q[j]);
    qs(q,l,j);
    qs(q,j+1,r);
}