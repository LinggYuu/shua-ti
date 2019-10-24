


//2^x * 2^y =2^(x+y)
// a^k
// 将k转为二进制
// 10=(1010)2
// a^k = a^(2^1) * a^(2^3)

// (A+B)modb=(Amodb+Bmodb)modb

// (A×B)modb=((Amodb)×(Bmodb))modb
// (A^2)modb=((Amodb)×(Amodb))modb
            // =(Amodb)^2modb





#include<iostream>
#include<algorithm>
using namespace std;

typedef long long ll;
int n;

// a^k%p
//a%p
//a^2%p=(a%p)(a%p)%p
//a^(2^2)%p=(a^2)%p*(a^2)%p %p
int qmi(int a,int k,int p)
{
    int res=1;
    while(k)//判断k是否为0
    {
        if(k&1)//判断当前k的末位是否为1  
            res=(ll)res * a % p;
            //只有该行用到(AB)%p公式
            //res是一个modp的结果
            //a是一个modp的结果
            //要得到的答案是(res*a)%p的结果
            //所以还要 modp
        //最开始a^(2^0)%p=a%p
        k=k>>1;//删去k的末位
        a=(ll)a * a % p; //算a^(2^x)%p
        // a^2%p 
        // (a^2)^2%p=(a^2%p)(a^2%p)%p
    } 
    return res;
} 

int main()
{
    scanf("%d",&n);
    while(n--)
    {
        int a,k,p;
        scanf("%d%d%d",&a,&k,&p);
        printf("%d\n",qmi(a,k,p));
    }




system("pause");
return 0;
}
