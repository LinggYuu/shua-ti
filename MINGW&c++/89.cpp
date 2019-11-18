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
//         A.push_back(a[i]-'0');//逆序存,654321
//     }
//     auto C=mul(A,b);
//     for(int i=C.size()-1;i>=0;i--)
//     {
//         cout<<C[i];
//     }
//     system("pause");
//     return 0;
// }