#include<iostream>
#include<string>
using namespace std;

int main()
{
    int num;
    char a[50][20];
    cin>>num;
    string word[20];
    for(int i=0;i<num;i++)
       {
            cin>>word[i];
            a[i][]=word[i];
       }
    for(int i=0;i<num;i++)
        {
            cout<<"the"<<i<<"is"<<word[i]<<endl;
            cout<<word[i].length()<<endl;
        }
    for(int i=num-2;i>=0;i--)
        word[i]+=word[i+1];
    cout<<word[0];



    system("pause");
    return 0;
}