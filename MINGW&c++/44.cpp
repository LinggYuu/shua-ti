//p1019
#include<iostream>
#include<string>
using namespace std;
string word[4];
string path;
int num,i,j,k;

string lj(string a,string b)
{
    int t,flag;
    string c;
    for(int i=a.size()-1;i>=0;i--)
        if(a[i]==b[0])
        {
            t=i;
            break;
        }
    for(int i=t,j=0;i<=a.size()-1;i++,j++)
    {   
        flag=1;
        if(a[i]!=b[j])
        {
            flag=0;
            break;
        }
    }
    if(flag==1)
        return c=a.substr(0,t)+b;
    else
        return "";
    
}

void dfs(int n,string c)
{
    if(n==num)
    {
        cout<<c;
        return;
    }
    cout<<lj(word[0],word[1]);
    

}
void shuchu(int b)
{
    cout<<b;
}

int main()
{
    cin>>num;
    for(i=0;i<num;i++)
    {
        cin>>word[i];
    }
    // dfs(0);
    shuchu(34);
    cout<<endl;
    cout<<word[0]<<","<<word[0].size()<<endl;
    cout<<word[1]<<","<<word[1].size()<<endl;
    // cout<<b;
    // dfs(0);

    system("pause");
    return 0;
}