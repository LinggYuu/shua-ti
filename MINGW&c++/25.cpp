#include<iostream>
using  namespace std;
int main()
{
    int num,i,j,x,y,flag=0;
    cin>>num;
    int n[10000][4];
    for(i=0;i<num;i++)
        cin>>n[i][0]>>n[i][1]>>n[i][2]>>n[i][3];

    cin>>x>>y;

    for(j=num-1;j>=0;j--)
        if(x<=n[j][0]+n[j][2]&&x>=n[j][0])
            {
                if(y>=n[j][1]&&y<=n[j][1]+n[j][3])
                {
                    cout<< j+1<<endl;
                    flag=1;
                    break;
                }
            }
    if(flag==0)
        cout<<-1<<endl;
    system("pause");
    return 0;
}