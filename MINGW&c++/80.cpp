// p1226

#include<iostream>
#include<algorithm>
using namespace std;

typedef long long ll;
int n;



//求a^k mod p
int qmi(int a,int k,int p)
{
    int res=1;
    while(k)//判断k是否为0
    {
        if(k&1)//判断当前k的末位是否为1
            res=(ll)res * a % p;
        k=k>>1;//删去k的末位
        a=(ll)a * a % p;
    }
    return res;
}
int main()
{
        int a,k,p;
        scanf("%d%d%d",&a,&k,&p);
        if(k==0)
        {
            printf("%d^%d mod %d=%d\n",a,k,p,a%p);
            return 0;
        }
        printf("%d^%d mod %d=%d\n",a,k,p,qmi(a,k,p));

system("pause");
return 0;
}
