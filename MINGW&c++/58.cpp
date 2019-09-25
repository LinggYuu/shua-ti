// p1031
#include<iostream>
#include<algorithm>
using namespace std;

int N;
int card[101];
int cnt;
int main()
{
    int ave;
    cin>>N;
    for(int i=1;i<=N;i++)
    {
        cin>>card[i];
        ave+=card[i];
    }
    ave/=N;
    for(int i=1;i<N;i++)
    {
        if(card[i]==ave)
            continue;
        else if(card[i]<ave)
        {
            card[i+1]-=ave-card[i];
            cnt++;         
        }
        else
        {
            card[i+1]+=(card[i]-ave);
            cnt++;
        }
    }
    cout<<cnt;
    system("pause");
    return 0;
}