// p1012
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
//关键在于string的相加与比较
const int N=25;
int n;
string x[N];
string t,a;

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>x[i];
    }
    for(int i=n-1;i>0;i--)
        for(int j=0;j<i;j++)
        {  
            if(x[j]+x[j+1]<x[j+1]+x[j])
                swap(x[j],x[j+1]);
        }
    for(int i=0;i<n;i++)
        cout<<x[i];
    
    system("pause");
    return 0;

}



