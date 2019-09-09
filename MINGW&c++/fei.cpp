#include<iostream>
using namespace std;

int main()
{

    if(!1)//0
        cout<<"aa"<<endl;
    if(1)//1
        cout<<"bb"<<endl;
    int c=1;
    if(!c)//0
        cout<<"cc"<<endl;
    if(c)//1
        cout<<"dd"<<endl;
    c=0;
    if(c)//0
        cout<<"ee"<<endl;
    if(!c)//1
        cout<<"ff"<<endl;
    





    system("pause");
    return 0;
}