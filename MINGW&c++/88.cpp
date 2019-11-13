// P2142
#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool cmp(vector<int>&a,vector<int>&b)
{
    if(a.size()!=b.size())
    {
        return a.size()>b.size();
    }
    for(int i=a.size()-1;i>=0;i--)//注意--
    {
        if(a[i]!=b[i])
        {
            return a[i]>b[i];
        }
    }
    return true;
}
vector<int> sub(vector<int>&A,vector<int>&B)
{
    vector<int>C;
    for(int i=0,t=0;i<A.size();i++)
    {
        t=A[i]-t;
        if(i<B.size())
            t-=B[i];
        C.push_back((t+10)%10);
        if(t<0)
            t=1;
        else 
            t=0;    
    }
    while(C.size()>1&&C.back()==0)//保证不出现003这种情况
    {
        C.pop_back();
    }
    return C;
}
//(t+10)%10)满足t≥0或t＜0
// 如果t>=0那么t就是t,t<0t就+10，t=t(t+10)%10


int main()
{
    string a,b;//123456,789
    vector<int>A,B,C;
    cin>>a>>b;
    for(int i=a.size()-1;i>=0;i--)
    {
        A.push_back(a[i]-'0');//逆序存,654321
    }
    for(int i=b.size()-1;i>=0;i--)
    {
        B.push_back(b[i]-'0');//987
    }
    if(cmp(A,B))
    {
        C=sub(A,B);
        for(int i=C.size()-1;i>=0;i--)
        {
            cout<<C[i];
        }
    }
    else
    {
        C=sub(B,A);
        cout<<'-';
        for(int i=C.size()-1;i>=0;i--)
        {
            cout<<C[i];
        }
    }
    system("pause");
    return 0;
}

//倒着表示
//765
//4321
// 模拟    1234
//        + 567
