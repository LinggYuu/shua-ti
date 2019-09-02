#include<iostream>
using namespace std;



void d(int n,int k)
{
    if(k<=0||n<0)
    {
        cout<<endl;
        return;
    }
    for(int i=1;i<n;i++)
    {          
            n-=i;
            cout<<i<<" ";
            k--;
            d(n,k);
            n+=i;
            k++;
    }

}


int main()
{
    int n,k;
    cin>>n>>k;
    d(n,k);



    system("pause");
    return 0;
}