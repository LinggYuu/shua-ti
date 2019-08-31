#include<iostream>
using namespace std;

int n;
int x[15];
int y[15];
int a[30];
int b[30];
int sum;
void dfs(int i)
{
    if(i>n)
        return;
    for(int j=1;j<=n;j++)
    {
        if(y[j]==0&&a[i+j]==0&&b[j-i+n]==0)
        {
            x[i]=j;
            y[j]=1;
            a[j+i]=1;
            b[j-i+n]=1;
            if(i==n)
            {
                sum++;
                if(sum<=3)
                {
                    for(int k=1;k<=n;k++)
                    cout<<x[k]<<" ";
                    cout<<endl;
                }
            }
            dfs(i+1);
            y[j]=0;
            a[i+j]=0;
            b[j-i+n]=0;
        }
    }

}

int main()
{
    cin>>n;
    dfs(1);
    cout<<sum<<endl;


    system("pause");
    return 0;
}