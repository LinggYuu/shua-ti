// p1115
#include<iostream>
using namespace std;

const int N=200010;

int num[N];
int s[N][N];
int n;

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        cin>>num[i];
    }
     for(int i=1;i<=n;i++)
    {
        cout<<num[i]<<endl;
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            s[i][j]=s[i-1][j];
            
        }
    cout<<s[1]<<","<<s[2]<<","<<s[3]<<endl;





    system("pause");
    return 0;
}