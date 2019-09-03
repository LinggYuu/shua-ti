//从1开始，S(0)=0
// [l,r]
// S(r)-S(l-1)


// #include<iostream>
// using namespace std;
// int main()
// {
//     int a[100010];
//     int s[100000+10];
//     int n,m;
//     cin>>n>>m;
//     s[0]=0;
//     for(int i=1;i<=n;i++)
//         cin>>a[i];
//     for(int i=0;i<=n;i++)
//         s[i]=s[i-1]+a[i];
//     while(m--)
//     {
//         int l,r;
//         cin>>l>>r;
//         cout<<s[r]-s[l-1]<<endl;
//     }



// }
#include<iostream>
using namespace std;

const int N=1010;
int n,m,q;
int a[N][N],s[N][N];
int main()
{
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>a[i][j];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i][j];
    while(q--)
    {
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        cout<<s[x2][y2]-s[x1-1][y2]-s[x2][y1-1]+s[x1-1][y1-1];

    }

    system("pause");
    return  0;













}