#include<iostream>
#include<string>
#include<cstring>
using namespace std;

void findr(string a,string b)
{
    if(a.size()<=0)
        return;
    else
    {
        int pos=b.size()-1;
        cout<<b[pos];
        int pos2=a.find(b[pos]);
        findr(a.substr(0,pos2),b.substr(0,pos2));
        findr(a.substr(pos2+1),b.substr(pos2,a.size()-pos2-1));
    }

}


int main()
{
    string a;
    string b;
    cin>>a;
    cin>>b;
    findr(a,b);

        // int pos=b.size()-1;
        // cout<<b[pos]<<endl;
        //  int pos2=a.find(b[pos]);
    // cout<<a.substr(0,pos2)<<" "<<b.substr(0,pos2);
    system("pause");
    return 0;
}
