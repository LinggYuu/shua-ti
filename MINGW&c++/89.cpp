// // p1303
// #include<iostream>
// #include<string>
// #include<vector>
// using namespace std;

// vector<int> mul(vector<int>&a,int b)
// {
//     vector<int>C;
//     int t=0;
//     for(int i=0;i<a.size()||t;i++)
//     {
//         if(i<a.size())
//             t+=a[i]*b;
//         C.push_back(t%10);
//         t/=10;
//     }
//     return C;
// }


// int main()
// {
//     string a;
//     int b;//123456,789
//     vector<int>A;
//     cin>>a>>b;
//     for(int i=a.size()-1;i>=0;i--)
//     {
//         A.push_back(a[i]-'0');
//     }
//     auto C=mul(A,b);
//     for(int i=C.size()-1;i>=0;i--)
//     {
//         cout<<C[i];
//     }
//     system("pause");
//     return 0;
// }



#include<iostream>
#include<string>
using namespace std;

int s[30],a,b,c,d;

void mul(int s[],int b)
{
    for(int i=1;i<=s[0];i++)
        s[i]*=b;
    for(int i=1;i<=s[0];i++)
    {
        if(s[i]>=10)
        {
            s[i+1]+=s[i]/10;
            s[i]%=10;
            if(i==s[0]) 
                s[0]++;
        }
    }
}


int main()
{
    s[0]=1;
    s[1]=1;
    cin>>a>>b;
    mul(s,a);
    mul(s,b);
    for(int i=s[0];i>=1;i--)
    {
        cout<<s[i];
    }

    system("pause");
    return 0;
}