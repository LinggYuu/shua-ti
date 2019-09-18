#include<iostream>
using namespace std;

//n>=8
int num[999]={6,2,5,5,4,5,6,3,7,6};
int cnt;


void x(int q,int i)
{
    for(int j=i;j<=999;j++)
    {
        int p=q;
        p-=num[j];
        if(p<=0)
            continue;
        int he=i+j;
        he=num[he];
        if(he==p)
        {
            if(i==j)
                cnt++;
            else
            {
                cnt+=2;
            }
            cout<<i<<","<<j<<"cnt:"<<cnt<<endl;    
        }
    }

}


int main()
{
    for(int i=10;i<=999;i++)
    {   
        int t=i;
        while(t>0)
        {
            int a=t%10;
            t/=10;
            num[i]+=num[a];
        }
        // cout<<"num"<<i<<"is"<<num[i]<<endl;
    }
    int n;
    int s;
    cin>>n;
    n-=4;
    for(int i=0;i<=999;i++)
    {
        n-=num[i];
        x(n,i);
        n+=num[i];
    }
    cout<<cnt;
    system("pause");
    return 0;

}