#include<iostream>
using namespace std;

int st[4]={1,2,3,4};


int cal(int l,int r)
{
    int s=0;
    for(int i=l;i<=r;i++)
    {
        s*=10;
        s+=st[i];
    }
    cout<<s;
    return s;
}

int main()
{
    for(int i=1;i<=3;i++)
    {
            for(int j=i+1;j<=3;j++)
            {
                int a=cal(0,i-1);
                int b=cal(i,j-1);
                int c=cal(j,3);
                cout<<a<<','<<b<<','<<c;
                cout<<endl;
            }
            cout<<endl;
    }
    system("pause");
    return 0;

}