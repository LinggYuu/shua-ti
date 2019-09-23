//p1032
#include<iostream>
#include<queue>
#include<string>
#include<algorithm>
#include<map>
using namespace std;

string s,e;
string l[6],r[6];
int cnt,num,t;
map<string,int>mm;
queue<int>step;

void bfs(string s)
{
    queue<string>cc;
    step.push(0);
    cc.push(s);
    while(!cc.empty()&&step.front()<=10)
    {
        // cout<<step.front();
        string ls=cc.front();
        int kk=step.front();
        if(mm[ls]>1)
        {    
            cc.pop();
            step.pop();    
        }
        if(kk>=10)
        {
            cout<<"NO ANSWER!";
            return;
        }
        step.pop();
        cc.pop();
        for(int i=0;i<ls.size();i++)
        {
            for(int j=0;j<cnt;j++)
            {
                if(ls.substr(i,l[j].size())==l[j])
                {
                    // cout<<ls.substr(i,l[j].size())<<l[j].size()<<",,"<<l[j]<<",,"<<j<<r[j]<<endl;
                    string d=ls;
                    d.replace(i,l[j].size(),r[j]);
                    mm[d]++;

                    step.push(kk+1);
                    // cout<<"di"<<kk+1<<"bu can be "<<d<<endl;
                    if(d==e)
                    {
                       cout<<kk+1<<endl;
                       return;     
                    }
                    cc.push(d);
                }
            }
        }
    }
}

int main()
{
    cin>>s>>e;
    cnt=0;
    while(cin>>l[cnt]>>r[cnt]) 
    {cnt++;}
    bfs(s);
    // for(int i=0;i<cnt;i++)
    // {
    //     cout<<l[i]<<","<<r[i]<<endl;
    // }

    system("pause");
    return 0;

}