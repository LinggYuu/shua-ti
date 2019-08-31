#include<iostream>
using namespace std;
int x[50];//"一"
int y[50];//"|"
int a[50];//"/"
int b[50];//"\"
int n;
int sum;
void dfs(int i)
{
    int j;
    if(i>n)
    {
        sum++;
        if(sum<=3)
        {
            for(int k=1;k<=n;k++)
                cout<<x[k]<<" ";
            cout<<endl;
        }
        return;
    }
    else
    {
        for(j=1;j<=n;j++)
        {
            if((y[j]==0)&&(a[i+j]==0)&&(b[n+j-i]==0))
            {
                x[i]=j;
                y[j]=1;
                a[i+j]=1;
                b[j-i+n]=1;
                dfs(i+1);
                y[j]=0;
                a[i+j]=0;
                b[j-i+n]=0;
            }
        }
        return;
    }
    

}

int main()
{
    
    cin>>n;
    dfs(1);
    cout<<sum<<endl;;
    system("pause");
    return 0;
}