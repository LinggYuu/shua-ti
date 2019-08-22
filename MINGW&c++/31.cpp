#include<iostream>
using namespace std;
int main()
{
    int N,M;
    int a[100100];
    int i,t=0;
    cin>>N>>M;
    for(i=0;i<N;i++)
        cin>>a[i];
    if(a[0]==M)
        {
            t++;
            a[0]=0;
        }
    for(i=1;i<N;i++)
    {   
        a[i]+=a[i-1];    
        if(a[i]>M)
        {
            a[i]-=a[i-1];
            a[i-1]=0;
            i--;
            t++;
        }
        else if(a[i]==M)
        {
            if(i!=N-1)
                a[i]=0;
            t++;
        }
        if(i==N-1&&a[i]<M)
            t++;

    }   
    cout<<t;

    system("pause");
    return 0;
}