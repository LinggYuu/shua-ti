// p1880
#include<iostream>
#include<algorithm>
using namespace std;

const int N=500;
int n,nn;
int s[N*2];
int f[N][N],ff[N][N];
int mi,ma;

//j-i+1为i到j的长度(含i,j)
int main()
{
    scanf("%d",&n);

    for(int i=1;i<=n;i++)
    {
        scanf("%d",&s[i]);
    }
    for(int i=n+1;i<=2*n-1;i++)
    {
        s[i]=s[i-n];
    }
    nn=n;
    n=n*2-1;
    // for(int i=1;i<=n;i++)
    // {
    //     cout<<s[i];
    // }

    for(int i=1;i<=n;i++)
    {
       s[i]+=s[i-1];
    }//前缀和

    for(int len=2;len<=nn;len++)
    {
        for(int i=1;i+len-1<=n;i++)//[i,i+len-1]得到长度为len的该区间
        {
          
            int l=i,r=i+len-1;  
            f[l][r]=1e8;
            ff[l][r]=-1e8;
            {
                for(int k=l;k<r;k++)
                {
                    f[l][r]=min(f[l][r],(f[l][k]+f[k+1][r]+s[r]-s[l-1]));
                    ff[l][r]=max(ff[l][r],(ff[l][k]+ff[k+1][r]+s[r]-s[l-1]));
                }
            }
        }
    }
    mi=1e8;    
    ma=-1e8;
    cout<<nn<<' '<<n<<endl;
    for(int i=1;i<=nn-1;i++)
    {
        // cout<<f[i][i+nn-1]<<endl;
        mi=min(mi,f[i][i+nn-1]);
        ma=max(ma,ff[i][i+nn-1]);
        cout<<ff[i][i+nn-1]<<endl;
    }
    cout<<mi<<endl<<ma<<endl;
    system("pause");
    return 0;

}