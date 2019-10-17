// p1026
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;



const int K=50,S=10;
int p,k,s;
string ww[K],dic[S];

string w;

int main()
{  
    cin>>p>>k;//k-1🔪
    for(int i=1;i<=p;i++)
    {
        cin>>ww[i];
        w+=ww[i];
    }
    cout<<w<<endl;
    cin>>s;
    for(int i=1;i<=s;i++)
    {
        cin>>dic[i];
    }






    system("pause");
    return 0;
}
