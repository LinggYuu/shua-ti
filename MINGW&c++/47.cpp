//1025
#include<iostream>
#include<algorithm>
using namespace std;

const int N=10;

int a[N];
int b[10010][N];
int n,nn,k,t=0,tt=0,num,sum=0;
int st[N];

void dfs(int s,int num,int tt)
{ 
    
    if(num==k-1)
    {
        // a[k-1]=nn;
        // for(int j=0;j<k;j++)
        // {   
        //     cout<<a[j]<<" ";
        // }
        sum++;
        // cout<<endl;
        return;
    } 
  
    for(int i=s;i<=nn/tt;i++)
    {    

            a[t]=i;
            nn-=i;
            t++;
            dfs(i,num+1,tt-1);
            t--;
            nn+=i;
    }



}


int main()
{
    cin>>n>>k;
    nn=n;
    tt=k;
    dfs(1,0,tt);
    cout<<sum;


    system("pause");
    return 0;

}