#include<iostream>
#include<algorithm>
#include<string>
#include<map>
using namespace std;
typedef long long ll;
int k,num=1,aa=1;
const ll N=1000000;
string n;
ll w[N];
ll s[N];
map<string,int>pp;
void dfs()
{
    cout<<n<<endl;
    pp[n]=1;
    for(int i=0;i<=n.size()-1;i++)
    {
        if(s[n[i]-'0']!=0)
        {
            int k=n[i]-'0';
            n[i]=s[n[i]-'0']+'0';
            if(pp[n]==1)
                continue;
            num+=1;
            dfs();
            n[i]=k+'0';
        }
    }
}

int main()
{
    cin.tie();
    cin>>n>>k;
    for(int i=1;i<=k;i++)
    {
        ll t;
        cin>>t>>s[t];
    }
    dfs();
    cout<<num;
    

    system("pause");
    return 0;
}
