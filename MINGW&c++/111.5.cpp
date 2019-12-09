#include<iostream>
using namespace std;
//下两行为较大规模二维数组的定义方法
const int MAX=1000;
int N,i=1,j=1,T=0,D=0,E=0;
int a[MAX][MAX];  
int main()
{
//读取输入数据 
cin>>N;
for(i=1;i<=N;i++)
{
    scanf("%d",&a[i][0]);
    for(j=1;j<=a[i][0];j++)
    {
        scanf("%d",&a[i][j]);
    }
}
//记录第i棵树最后一次统计苹果个数时的列下标index[i]
int index[N+1];
for(i=1;i<=N;i++)
{
for(j=1;j<=a[i][0];j++)
{
if(a[i][j]>0) index[i]=j;
}
}
//将每棵树从第index个数据开始之后的所有数据相加即为该树最后剩-
//-下的苹果数 
for(i=1;i<=N;i++)
{
for(j=index[i];j<=a[i][0];j++)
{
T+=a[i][j];
}
} 
//将每棵树第一次统计的苹果个数减去index之前疏果的个数，结果与-
//-最后一次统计的苹果个数相比，若大，则该树有苹果掉落 
int Throw[N+1],sum[N+1];
bool Drop[N+1]; //bool类型数组要先定义，下面再初始化否则报错 
for(i=1;i<=N;i++)
{
Throw[i]=0,Drop[i]=false; 
for(j=2;j<index[i];j++)
{
if(a[i][j]<=0) Throw[i]+=a[i][j];
}
sum[i]=a[i][1]+Throw[i];
if(sum[i]>a[i][index[i]])
{
D++;
Drop[i]=true;
} 
} 
//判断如果连续三棵树有掉落，则E自增；由于是环形，开头和结尾都-
//-有掉落的情况需特殊处理 
    for(i=2;i<N;i++)
    {
        if(Drop[i]&&Drop[i-1]&&Drop[i+1])
        {
            E++;
        }
    }
    if(Drop[1]&&Drop[N]) 
    {
        if(Drop[2]) E++;
        if(Drop[N-1]) E++;
    }

    printf("%d %d %d",T,D,E);
    system("pause");
    return 0;
}