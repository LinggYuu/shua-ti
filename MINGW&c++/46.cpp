//p1179

#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int i,L,R,num=0;
    cin>>L>>R;
    for(i=L;i<=R;i++)
    {
        int t=i;
        while(t>0)
        {   
            if(t%10==2)
            {
                num++;
            }
            t/=10;
        }
    }
    cout<<num;



    system("pause");
    return 0;
}
