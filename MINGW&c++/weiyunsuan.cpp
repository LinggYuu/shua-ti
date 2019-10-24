// #include<iostream>
// using namespace std;
// // 1(2^0) 2(2^1) 4(2^2) 8(2^3) 16(2^4) 32(2^5) 
// // 64(2^6) 128(2^7) 256(2^8) 512(2^9) 1024(2^10)

// // x=1010
// // 源码 0000...1010
// // 反码 11111...0101 全取反
// // 补码 1111...0110  取反加1




// int main()
// {
//     cout<<(4<<1)<<endl;//x2的1次方  100<<1 1000
//     cout<<(4>>1)<<endl;//÷2的1次方  100>>1 010
//     int n=10;//1010
//     for(int k=3;k>=0;k--)
//     {
//         cout<<(n>>k&1);
//     }
    
    
//     system("pause");
//     return 0;
// }
// // &1
// // 位数是0123...从0开始
// // n>>k&1 看n的第k位数字是几


// // lowbit(x);//返回x的最后一位1
// // x=1010 lowbit(x)=10
// // x=101000  lowbit(x)=1000

// // 统计x中1的个数
// #include<iostream>
// using namespace std;

// int lowbit(int x)
// {
//     return x&-x;
// }

// int main()
// {
//     int n;
//     cin>>n;//n个数
//     while(n--)//n次  
//     {
//         int x;
//         cin>>x;

//         int res=0;
//         while(x)
//         {   
//             x-=lowbit(x);
//             res++;
//         }
//         cout<<res<<endl;
//     }



// }



//判断k的二进制有几位
#include<iostream>
using namespace std;

int a,k,p;
int qmi(int k)
{
    int res=0;
    while(k)
    {
        res++;
        k=k>>1;//删去k的末位
    }
    return res;
}
int main()
{
    cin>>k;
    cout<<qmi(k);
    system("pause");
    return 0;

}