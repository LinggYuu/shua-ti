//quicksort
#include<iostream>
using namespace std;

void swap(int &a,int &b)
{
    int t=a;
    a=b;
    b=t;
}
void bs(int s[],int N)
{
    for(int j=N-1;j>0;j--)
        for(int i=0;i<j;i++)
            if(s[i]>=s[i+1])
                swap(s[i],s[i+1]);

}

void quicksort(int s[],int left,int right)
{
    if(left>=right)
        return;
    int i=left,j=right;
    int k=rand() % (right - left + 1) + left;
    swap(s[i],s[k]);
    int x=s[i];
    while(i<j)
    {
        if(s[i]=s[j])
            break;
        while(i<j&&s[j]>=x)
            j--;
        if(i<j)
            s[i++]=s[j];
        while(i<j&&s[i]<x)
            i++;
        if(i<j)
            s[j--]=s[i];
    }
    s[i]=x;
    quicksort(s,left,i-1);
    quicksort(s,i+1,right);
}


int main()
{
int a[100010];
int N;
int i;
cin>>N;
for(i=0;i<N;i++)
{
    a[i]=1;
    
}

quicksort(a,0,N-1);

for(i=0;i<N;i++) 
    cout<<a[i]<<" ";


    
    system("pause");
    return 0;
}



















