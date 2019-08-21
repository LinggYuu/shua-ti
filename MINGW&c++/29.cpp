#include<iostream>
using namespace std;

void swap(int &a,int &b)
{
    int t;
    t=a;
    a=b;
    b=t;
}

int main()
{
    int n,num,i,j;
    cin>>n>>num;
    int a[5000];
    int b[5000];
    for(i=0;i<n;i++)
        cin>>a[i]>>b[i];
    for(j=n-1;j>0;j--)
        for(i=0;i<j;i++)
            if(b[i]<b[i+1])
            {
					swap(a[i],a[i+1]);
					swap(b[i],b[i+1]);      
            }
			else if(b[i]==b[i+1])
			{
				if(a[i]>a[i+1])
					swap(a[i],a[i+1]);
			}
num*=1.5;
i=0;
while(num>0)
{
    i++;
    num--;   
    while(num==0)
    {
        if(b[i]==b[i-1])
            {
                i++;
            }
        else
            break;
    }

}
cout<<b[i-1]<<" "<<i<<endl;
for(j=0;j<i;j++)
    cout<<a[j]<<" "<<b[j]<<endl;


system("pause");
return 0;

}

