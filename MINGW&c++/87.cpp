// P1601
#include<iostream>
#include<vector>
#include<string>
#include<cstring>
using namespace std;

const int N=10e6+10;

vector<int> add(vector<int>&A,vector<int>&B)
{
    vector<int>C;
    int t=0;//进位，也是该位结果
    for(int i=0;i<A.size()||i<B.size();i++)
    {
        if(i<A.size())t+=A[i];
        if(i<B.size())t+=B[i];
        C.push_back(t%10);
        t/=10;//得进位
    }
    if(t)
        C.push_back(1);
    return C;
}



int main()
{
    string a,b;//123456,789
    vector<int>A,B;
    cin>>a>>b;
    for(int i=a.size()-1;i>=0;i--)
    {
        A.push_back(a[i]-'0');//逆序存,654321
    }
    for(int i=b.size()-1;i>=0;i--)
    {
        B.push_back(b[i]-'0');//987
    }
    auto C=add(A,B);
    for(int i=C.size()-1;i>=0;i--)
    {
        cout<<C[i];
    }

    system("pause");
    return 0;
}

//倒着表示
//765
//4321
// 模拟    1234
//        + 567
