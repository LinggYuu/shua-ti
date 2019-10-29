// //                 存储图
// // 单链表:邻接表《
// //                 树

// // 双链表:优化某些问题
// // e[N],       ne[N]
// // 该点的值     该点的指向(next指针)







// //单链表，只往前看
// // head->o(3)0->o(5)1->o(7)2->o(9)3->空
// // e[0]=3,ne[0]=1,e[1]=5,ne[1]=2,
// // e[2]=7,ne[2]=3,e[3]=9,ne[3]=-1

// #include<iostream>
// using namespace std;

// const int N=10010;
// int head,e[N],ne[N],idx;
// //head表示头结点下标，e[i]表示结点i的值，
// //ne[i]表示结点i的next指针是多少，是个位置
// void init()//初始化
// {
//     head=-1;
//     //head指向-1，可以理解为head的next指针为空
//     idx=0; 
// }

// //x插到头结点，用的极多*****
// void add_to_head(int x)
// {
//     e[idx]=x;
//     ne[idx]=head;
//     // 插入的结点的next指针指向head指向的指针
//     head=idx;
//     //head指向插入的结点指针
//     idx++;
// }

// //x插到下标为k的点后
// void add(int k,int x)
// {
//     e[idx]=x;
//     ne[idx]=ne[k];
//     ne[k]=idx;
//     idx++;
// }

// //删除下标是k的后面的点删掉
// void remove(int k)
// {
//     ne[k]=ne[ne[k]];
// }



// // `````





// // 双链表
// #include<iostream>
// using namespace std;
// const int N=100010;

// int m;
// int e[N],l[N],r[N],idx;

// //初始化
// void init()
// {
//     //下标为0的为head，为1的为tail  
//     //0head左端点，1tail右端点
//     r[0]=1;
//     l[1]=0;
//     idx=2;
// }
// //在k的右边插入x
// void add(int k,int x)
// {
//     e[idx]=x;
//     r[idx]=r[k];
//     l[idx]=k;
//     l[r[k]]=idx;//必须先这一步
//     r[k]=idx;
// }
// //k的左边插入，为在l[k]的右边插入

// //删除第k个点
// void remove(int k)
// {
//      r[l[k]]=r[k];//左边的右边直接等于右边
//      l[r[k]]=l[k];//右边的左边直接等于左边
// }



// // ````````````````````````````





// // 栈:先进后出

// // 队列:先进先出


// #include<iostream>
// using namespace std;

// const int N=10010;

// //**********栈:
// int stk[N];
// int tt=0;
// int x;

// // 插入
// stk[++tt]=x;
// // 这里从1开始插，tt下标存放x

// // 弹出,删除 
// tt--;

// // 判断栈是否为空
// // 因为从1开始插所以只要>=1便说明有元素
// if(tt>0) 
//     not empty;
// else 
//     empty;

// // 栈顶
// // 取出栈顶,栈顶即最后放入在tt的元素
// stk[tt];





// //*********队列:
// int q[N],hh=0,tt=-1;//hh队头，tt队尾，0或-1看习惯
// //在队尾插入元素，在队头弹出元素    
// //这里队尾为-1插入的第一个位置为0
// // y总 栈习惯从0，队列从-1
// //插入
// q[++tt]=x;

// //弹出
// hh++; 

// //是否为空
// if (hh<=tt) not empty
// else empty

// //取出队头元素
// q[hh]
// q[tt]


// //题目解法:
// // 1.暴力算法怎么做
// // 2.如何去优化


// //单调栈

// int n;
// int stk[N],tt;

// int main()
// {
//     cin>>n;

//     for(int i=0;i<n;i++)
//     {
//         int x;
//         cin>>x;
//         while(tt&&stk[tt]>=x)
//         //一直删删到找到一个小于x的stk[tt]
//         //保证了单调递增
//             tt--;
//         if(tt) //不空说明找到了一个栈左边且小于x的值
//             cout<<stk[tt]<<" ";
//         else 
//             cout<<-1<<" ";
//         stk[++tt]=x;//插入栈中
//     }

//     return 0;
// }
// 1：26



// //单调队列

// //滑动窗口最大值

// #include<iostream>
// using namespace std;

// const int N=10010;
// //队列维护窗口
// int a[N],q[N];
// int n,k;
// int main()
// {
//     cin>>n>>k;
//     for(int i=0;i<n;i++)
//         cin>>a[i];
//     int hh=0,tt=-1;
//     for(int i=0;i<n;i++)
//     // q中存的是下标
//     {//i-k+1是[i-k+1,i]长度为k
//         if(hh<=tt && i-k+1>q[hh])
//         //判断队头是否划出窗口
//             hh++;
//         while(hh<=tt && a[q[tt]]>=a[i])
//         //新插的数小于队尾的数的话
//             tt--;
//         q[++tt]=i;
//         if(i>=k-1)
//             cout<<a[q[hh]]<<" ";
//     }
// }


// // KMP 
// #include<iostream>

// using namespace std;

// const int N=10010,M=100010;

// int n,m;
// char p[N],s[M];
// int ne[N];

// int main()
// {
//     cin>>n>>p+1>>m>>s+1;//p,s下标从1开始输入
//     //求ne
//     //j是一个长度，也是一个下标
//     for(int i=2,j=0;i<=n;i++)
//     {
//         while(j&p[i]!=p[j+1]) j=ne[j];
//         if(p[i]==p[j+1]) j++;
//         ne[i]= j;
//     }

//     //匹配
//     //j是与s匹配的最后一个字母位置
//     for(int i=1,j=0;i<=n;i++)
//     {
//         while(j&&s[i]!=p[j+1])
//         //p与当前s [i]匹配的是j+1
//             j=ne[j];
//         if(s[i]==p[j+1])
//             j++;
//         if(j==m)
//         {
//             printf("%d",i-n);
//             j=ne[j]; //匹配成功
//         }
//     }
//     system("pause");
//     return 0;
// }


//Trie树
//高效地存储和查找字符串集合的数据结构


#include<iostream>
using namespace std;

const int N=100010;
//字符串总长度不超过10^5,所以最多有10^5个结点 
int son[N][26],cnt[N],idx;
char str[N];
//idx 为下标 ，下标是0的点，既是根节点又是空节点
// 因为只有小写字母所以每个结点最多向外连26条边
//son存树中每个点的所有儿子
//cnt存以当前这个点结尾的有多少个

void insert(char str[])
{
    int p=0;
    for(int i=0;str[i];i++)
    {
        int u=str[i]-'a';//小写字母a-z映射成0-25
        if(!son[p][u])
            son[p][u] = ++idx;
        p=son[p][u];
    }
    cnt[p]++;
}

int query(char str[])
{
    int p=0;
    for(int i=0;str[i];i++)
    {
        int u=str[i]-'a';
        if(!son[p][u])
            return 0;
        p=son[p][u];
    }
    return cnt[p];
}

int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        char op[2];
        scanf("%s%s",op,str);
        if(op[0]=='I')
            insert(str);
        else
            printf("%d\n",query(str)); 
    }

    system("pause");
    return 0;
}