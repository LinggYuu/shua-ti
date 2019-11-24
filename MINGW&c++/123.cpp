// #include<iostream>
// using namespace std;
// const int K=1000000007;
// int a[10000010];
// int dp[10000010];
// int c[10000010];
// int st[10000010];


// int main(){
// 	int n;
// 	cin>>n;
// 	for(int i=1;i<=n;i++){
// 		cin>>a[i];
// 	}
// 	dp[1]=1;
// 	st[a[1]]=1;
// 	for(int i=2;i<=n;i++)
// 	{
// 		if(st[a[i]]==1)
// 		{
// 			for(int j=i-1;j>=1;j--)
// 			{
// 				if(a[j]==a[i])
// 				dp[i]-=c[j];
// 			}
// 		}
// 		dp[i]=(dp[i-1]*2+1+K)%K;
// 		c[i]=dp[i]-dp[i-1];
// 		st[a[i]]=1;
// 		cout<<i<<dp[i]<<c[i]<<endl;
// 	}
// 	cout<<dp[n-1];
// 	system("pause");
// 	return 0;

// }

// #include<iostream>
// #include<cstdio>
// #include<cstring>
// #define MOD 1000000007
// #define MAXN 1000005
// typedef long long LL;
// LL f[MAXN];
// int last[MAXN],a,n;
// int main()
// {
// 	while(~scanf("%d",&n))
// 	{
// 		memset(last,0,sizeof(last));
// 		f[0]=0;
// 		for(int i=1;i<=n;++i)
// 		{
//             scanf("%d",&a);
// 			f[i]=(f[i-1]<<1)%MOD;
// 			if(!last[a]) last[a]=i,f[i]++;
// 			else f[i]=(f[i]-f[last[a]-1]+MOD)%MOD,last[a]=i;
// 		}
// 		printf("%I64d\n",f[n]%MOD);
// 	}
// 	system("pause");
// 	return 0;
// }




#include<iostream>
using namespace std;
const int N=100010;
const int K=1000000007;
int n;
char a[N];
int sum;
int f[N];//以第N个数结尾的子序列
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        f[i]=1;
        for(int j=1;j<i;j++)
        { 
            if(a[j]==a[i])
            {
                f[i]-=f[j];
            }
            f[i]=(f[i]+f[j]+K)%K;
        }
        sum=(sum+f[i]+K)%K;
    }
    cout<<sum;
    system("pause");
    return 0;
}
