#include<iostream>
using namespace std;
const int N=10050;
int T,D,E,f;
int num;
long long tree[N][N];

int main()
{
    cin>>num;
    for(int i=1;i<=num;i++)
    {
        int a=0;
        cin>>tree[i][0];
        a=tree[i][0];
        for(int j=1;j<=a;j++)
        {
            cin>>tree[i][j];
        }
        tree[i][a+1]=tree[i][1];
    }
    for(int i=num+1,j=1;j<=2;i++,j++)
    {
        for(int a=0;a<=tree[j][0]+1;a++)
        {
            tree[i][a]=tree[j][a];
        }
    }
    for(int i=1;i<=num+2;i++)
    {
        for(int j=2;j<=tree[i][0];j++)
        {
            if(tree[i][j]<=0)
            {
                tree[i][tree[i][0]+1]+=tree[i][j];
            }            
            else
            {
                if(tree[i][tree[i][0]+1]>tree[i][j])
                {
                    tree[i][tree[i][0]+2]=1;
                    tree[i][tree[i][0]+1]=tree[i][j];
                }
            }
        }
        if(i<=num)
            T+=tree[i][tree[i][0]+1];
    }
    // for(int i=1;i<=num+2;i++)
    // {
    //     for(int j=0;j<=tree[i][0]+2;j++)
    //         cout<<tree[i][j]<<" ";
    //     cout<<endl;
    //     if(i>=num)
    //         cout<<endl;
    // }
    for(int i=1;i<=num;i++)
    {
        if(tree[i][tree[i][0]+2]!=0)
        {
            D++;
            if(tree[i+1][tree[i+1][0]+2]==1&&tree[i+2][tree[i+2][0]+2]==1)
            {
                E++;
            }
        }
    }
    cout<<T<<" "<<D<<" "<<E;
    return 0;
}