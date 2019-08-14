#include <iostream>
#include <queue>
#include <cstdio>
#include <cstdlib> 
#include <algorithm>
#include <cstring>
using namespace std;    

int main()
{
    queue<int>q;
    queue<int>p;
    int M,N,n[1000],t=0,flag=1;
    int i;
    cin>>M>>N;
    for(i=0;i<N;i++)
    { 
           cin>>n[i];
    }

    for(i=0;i<N;i++)
    {   
        q=p;
        while(!q.empty())
        {   
            
            flag=1;
            if(q.front()!=n[i])
                 {  
                     q.pop(); 
                 }
            else
            {
                flag=0;//有相同
                break;
            }
        }
        if(flag==1)
        {
            if(int(p.size())<M)
                p.push(n[i]);
            else 
            { 
                p.pop();
                p.push(n[i]);   
            }
            t++;
        }

           
     }
    // while(!p.empty())
    // {
    //     cout<<p.front()<<endl;
    //     p.pop();
    // }
    cout<<t<<endl;

    system("pause");
    return 0;
}