#include<iostream>
#include<string>
#include<cstring>
using namespace std;


const int N=110,Q=110,S=110;
int n,q;
struct T
{
    string tm;
    string da; 
}ti[N];
struct TT
{
    string ttm;
    string dda[5];
}tti[N];

int main()
{
    cin.tie();
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>ti[i].tm>>ti[i].da;
    }
    for(int j=1;j<=q;j++)
    {
        cin>>tti[j].ttm;
        for(int k=1;k<=4;k++)
        {
            cin>>tti[j].dda[k];
        }
    }    

    for(int i=1;i<=q;i++)
    {

        for(int j=1;j<=n;j++)
        {
            if(tti[i].ttm==ti[j].tm)
            {
                for(int k=1;k<=4;k++)
                {   
                    if(tti[i].dda[k]==ti[j].da)
                    {  
                        if(k==1) cout<<'A'<<endl;
                        else if(k==2) cout<<'B'<<endl;
                        else if(k==3) cout<<'C'<<endl;
                        else if(k==4) cout<<'D'<<endl;
                        break;
                    }
                }
            
            }
        }

    }

    system("pause");
    return 0;

}
            // if(k==1) tti[j].dd[k]='A';
            // else if(k==2) tti[j].dd[k]='B';
            // else if(k==3) tti[j].dd[k]='C';
            // else if(k==4) tti[j].dd[k]='D';