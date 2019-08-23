#include<iostream>
#include<algorithm>
using namespace std;

void swap(int &a,int &b)
{
    int t=a;
    a=b;
    b=t;
}



int main()
{
    int n,m,i,j,v=0,w=0;
    int a[5000][2];
    cin>>n>>m;
    for(i=0;i<m;i++)
        cin>>a[i][0]>>a[i][1];
    for(i=m-1;i>0;i--)
        for(j=0;j<i;j++)
            if(a[j][0]>=a[j+1][0])
                {
                    swap(a[j][0],a[j+1][0]);
                    swap(a[j][1],a[j+1][1]);
                }

cout<<endl;
    for(i=0;i<m;i++)
        cout<<a[i][0]<<" "<<a[i][1]<<endl;
i=0;
while(n>0)
{
    n-=a[i][1];
    v+=a[i][1]*a[i][0];
    
    if(n<0)
    {
        n+=a[i][1];
        v-=(a[i][1]-n)*a[i][0]; 
        break;       
    } 
    i++;    
   
}
cout<<v;
system("pause");
return 0;
}