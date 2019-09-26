// p1042
#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
const int N=25*2600;
char sy[N][100];
char ey[N][100];

string s;
int main()
{   
    int cnt=0;
    int t=1,tt=1,st,et,i=0;
    int w=0,l=0,ll=0,ww=0;
    getline(cin,s,'E');
    for(i=0,st=0,et=0;i<s.size();i++)
    {
        if(s[i]=='\n')
            continue;
        if(s[i]=='W')
        {
            w++;
            ww++;
        }
        if(s[i]=='L')
        {
            l++; 
            ll++;   
        }
        sy[st][t++]=s[i];
        ey[et][tt++]=s[i];

        if((w>=11||l>=11)&&(w-l<=-2||w-l>=2))
        {
            st++;
            t=1;
            w=0;
            l=0;
        }
        if((ww>=21||ll>=21)&&(ww-ll>=2||ww-ll<=-2))
        {
            et++;
            tt=1;
            ww=0;
            ll=0;
        }
    }
    for(int j=0;j<=st;j++)
    {
        int wf=0,lf=0;
        for(int k=1;sy[j][k]!='\0';k++)
        {
            if(sy[j][k]=='W')
                wf++;
            else if(sy[j][k]=='L')
                lf++;
        }
        cout<<wf<<':'<<lf<<endl;
    }
    cout<<endl;
    for(int j=0;j<=et;j++)
    {
        int wf=0,lf=0;
        for(int k=1;ey[j][k]!='\0';k++)
        {
            if(ey[j][k]=='W')
                wf++;
            else if(ey[j][k]=='L')
                lf++;
        }
        cout<<wf<<':'<<lf<<endl;
    }

    system("pause");
    return 0;

}