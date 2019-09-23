                存储图
单链表:邻接表《
                树

双链表:优化某些问题
e[N],       ne[N]
该点的值     该点的指向(next指针)

head->o(3)0->o(5)1->o(7)2->o(9)3->空
e[0]=3,ne[0]=1,e[1]=5,ne[1]=2,
e[2]=7,ne[2]=3,e[3]=9,ne[3]=-1

#include<iostream>
using namespace std;

const int N=10010;
int head,e[N],ne[N],idx;
//head 指向第一个元素，值是位置
void init()//初始化
{
    head=-1;
    idx=0; 
}
//x插到头结点
void add_to_head(int x)
{
    e[idx]=x;
    ne[idx]=head;
    head=idx;
    idx++;
}
//x插到下标为k的点后
void add(int k,int x)
{
    e[idx]=x;
    ne[idx]=ne[k];
    ne[k]=idx;
    idx++;
}
//删除下标是k的后面的点删掉
void remove(int k)
{
    ne[k]=ne[ne[k]];
}



`````





双链表
#include<iostream>
using namespace std;
const int N=100010;

int m;
int e[N],l[N],r[N],idx;

//初始化
void init()
{
    //0head左端点，1tail右端点
    r[0]=1;
    l[1]=0;
    idx=2;
}
//在k的右边插入x
void add(int k,int x)
{
    e[idx]=x;
    r[idx]=r[k];
    l[idx]=k;
    l[r[k]]=idx;
    r[k]=idx;
}
//k的左边插入，为在l[k]的右边插入

//删除第k个点
void remove(int k)
{
    r[l[k]]=r[k];
    r[k]=l[k];
}




``````



栈:先进后出

队列:先进先出


#include<iostream>
using namespace std;

const int N=10010;


//**********栈:
int stk[N],tt=0;


插入
stk[++tt]=x；

弹出 
tt--;

判断栈是否为空
if(tt>0) not empty
else empty

栈顶
stk[tt];



//*********队列:
int q[N],hh,tt=-1;//hh队头，tt队尾，0或-1看习惯
//在队尾插入元素，在队头弹出元素    


//插入
q[++tt]=x;

//弹出
hh++; 

//是否为空
if (hh<=tt) not empty
else empty

//取出队头元素
q[hh]
q[tt]






//单调栈

int n;
int stk[N],tt;

int main()
{
    cin>>n;

    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        while(tt&&stk[tt]>=x)
            tt--;
        if(tt) 
            cout<<stk[tt]<<" ";
        else 
            cout<<-1<<" ";
        stk[++tt]=x;
    }

    return 0;
}

//单调队列

#include<iostream>
using namespace std;

const int N=10010;

int a[N],q[N];

int main()
{
    cin>>n>>k;
    for(int i=0;i<n;i++)
        cin>>a[i];
    int hh=0,tt=-1;
    for(int i=0;i<n;i++)
    {
        if(hh<=tt && i-k+1>q[hh])
            h++;
        while(hh<=tt && a[q[tt]]>=a[i])
            tt--;
        q[++tt]=i;
        if(i>=k-1)
            cout<<a[q[hh]]<<" ";

    }
}