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
//数组模拟的指针


// idx:0;cr,1;cr,2

// x
// son[x][1]
// son[son[x][1]]
// son[][]中存的是该节点地址

// #include<iostream>
// using namespace std;

// const int N=100010;
// //字符串总长度不超过10^5,所以最多有10^5个结点 
// int son[N][26],cnt[N],idx;
// char str[N];
// //idx 为下标 ，下标是0的点，既是根节点又是空节点
// //意思是如果一个点没有子节点也会让他指向0
// // 因为只有小写字母所以每个结点最多向外连26条边
// //son存树中每个点的所有儿子
// //cnt存以当前这个点结尾的有多少个
// // son[][]中的值都是唯一的，可当作地址下一个的p
// void insert(char str[])
// {
//     int p=0;
//     //从根节点开始
//     for(int i=0;str[i];i++)
//     {
//         int u=str[i]-'a';//小写字母a-z映射成0-25
//         if(!son[p][u])
//         //p节点不存在u这个儿子 
//             son[p][u] = ++idx; 
//         p=son[p][u];
//     }
//     cnt[p]++;
// }

// int query(char str[])
// {
//     int p=0;
//     for(int i=0;str[i];i++)
//     {
//         int u=str[i]-'a';
//         if(!son[p][u])
//             return 0;
//         p=son[p][u];
//     }
//     return cnt[p];
// }

// int main()
// {
//     int n;
//     cin>>n;
//     while(n--)
//     {
//         char op[2];
//         scanf("%s%s",op,str);
//         if(op[0]=='I')
//             insert(str);
//         else
//             printf("%d\n",query(str)); 
//     }

//     system("pause");
//     return 0;
// }







// //并查集
// // 1.将两个集合合并
// // 2.询问两个元素是否在一个集合当中

// //基本原理:每个集合用一棵树来表示。树根的编号
// //就是整个集合的编号。每个节点存储他的父节点，
// //p[x]表示x的父节点

// // q1:如何判断树根: if(p[x]==x)
// // q2:如何求x的集合编号:while(p[x]!=x) x=p[x];
// // q3:如何合并两个集合
//     //px是x的集合编号，py是y的集合编号。p[x]=y

// #include<iostream>

// using namespace std;

// const int N=100;
// int n,m;
// int p[N];//每个元素的父节点是谁，一个地址应该
// int size[N];


// //最重要
// int find(int x)
// //返回x所在集合的编号，即返回x的祖宗节点+路径压缩(优化)
// {
//     if(p[x]!=x)//x不是根节点
//         p[x]=find(p[x]);
//     return p[x];
// }




// int main()
// {
//     cin.tie();
//     cin>>n>>m;
//     for(int i=1;i<=n;i++)
//     {
//         p[i]=i;
//     }

//     while(m--)
//     {
//         char op[2];
//         //scanf读字符串时会自动忽略空格回车
//         //所以op[2]
//         int a,b;
//         scanf("%s%d%d",op,&a,&b);
//         if(op[0]=='M')//合并
//         {
//             p[find(a)]=find(b);
//             //b的祖宗节点成为a的祖宗节点的爷
//         }
//         else
//         {
//             if(find(a)==find(b))
//                 puts("Yes");
//             else
//                 puts("No");   
//         }

//         //妙啊
//     }

//     system("pause");
//     return 0;
// }



//堆(手写)
// 一个完全二叉树
//小根堆:每个点都小于等于左右儿子，根节点是最小值


// 堆の存储
// 下标从1开始不然左右儿子不好搞
//用一维数组
// 根节点是1号点
// x的左儿子:2x
// x的右儿子:2x+1


//1.插入一个数
//2.求集合当中的最小值
//3.删除最小值
// 1-3最基本操作
//4.删除任意一个元素
//5.修改任意一个元素

//用下面两个操作可实现上面5个操作
// down(x)//往下调整
// up(x)//往上调整

// 1.插入一个数 
//size表示当前堆的大小(既是大小也是地址)，
//heap表示堆
//heap[++size]=x,在树的最后面插入x；
//up(size);

//2.求集合中的最小值
//heap(1);

//3.删除最小值
//若要删除最后一个元素，只要size--
//若要删最小值(若为小根堆就删)
//heap[1]=heap[size];size--;down(1);

//4.删除任意一个元素
// heap[k]=heap[size];size--;down(k),up(k);
//down和up只会执行一个

//5.修改任意一个元素
//heap[k]=x;down(k),up(k);

// #include<iostream>
// #include<algorithm>
// using namespace std;

// const int N=100010;

// int n,m;
// int heap[N];
// int si;
// //size存当前heap中有多少个元素

// void down(int u)
// {
//     int t=u; 
//     //用t来存爸爸和两儿子这一组中的最小的节点编号
//     if(u*2<=si&&heap[u*2]<heap[t])
//         t=u*2;
//     if(u*2+1<=si &&heap[u*2+1]<heap[t])
//         t=u*2+1;
//     if(u!=t)
//     {
//         swap(heap[u],heap[t]);
//         down(t);
//     }
// }
// void up(int u)
// {
//     while(u/2&&heap[u/2]>heap[u])
//     {
//         swap(heap[u/2],heap[u]);
//         u=u/2;
//     }
// }
// int main()
// {
//     scanf("%d",&n);
//     for(int i=1;i<=n;i++)
//         scanf("%d",&heap[i]);
//     si=n;
//     for(int i=n/2;i;i--)
//         down(i);
//     while(m--)
//     {
//         printf("%d",heap[1]);
//         heap[1]=heap[si];
//         si--;
//         down(1);
//     }


//     system("pause");
//     return 0;
// }



//离散化是极特殊的哈希方式

// hash表
//                     开放寻址法(y总常用)
//         存储结构{
// 哈希表{             拉链法
//         字符串哈希方式

// --------------------------------------
// 大空间的一堆数据映射到小空间

// 10^5
// -10^9~10^9
// h(x)=(0,10^5)

// 1.x mod 10^5
//这里取模(mod number)的一般是个质数
// 2.冲突(重复)

// 哈希函数


// 拉链法 
// 开一维数组存哈希数
    // for(int i=100000;;i++)
    // {
    //     bool flag=true;
    //     for(int j=2;j*j<i;j++)
    //     {
    //         if(i%j==0)
    //         {
    //             flag=false;
    //             break;
    //         }
    //     }
    //     if(flag)
    //     {
    //         cout<<i<<endl;
    //         break;
    //     }
    //     //找到大于100000的第一个质数
    //     //用于取模的质数
            // 得100003
    // }
// #include<iostream>
// #include<cstring>
// using namespace std;

// const int N=100003;
// int h[N],e[N],ne[N],idx;

// void insert(int x)
// {
//     int k=(x%N+N)%N;
//     //如-10%3会是-1
//     //如果x是负数%N负数，+N再%N保证都为正数且小于等于N
//     e[idx]=x;
//     ne[idx]=h[k];
//     h[k]=idx++;  
// }
// bool find(int x)
// {
//     int k=(x%N+N)%N;
//     for(int i=h[k];i!=-1;i=ne[i])
//     {
//         if(e[i]==x)
//         {
//             return true;
//         }
//         else 
//             return false;
//     }
// }



// int main()
// {
//     int n;
//     scanf("%d",&n);

//     memset(h,-1,sizeof h);
//     while(n--)
//     {
//         char op[2];
//         int x;
//         scanf("%s%d",op,&x);

//         if(op[0]=='I')
//             insert(x);
//         else
//         {
//             if(find(x))
//                 puts("yes");
//             else
//                 puts("no");
//         }
//     }




//     system("pause");
//     return 0;
// }



//开放寻址法
//只开一个一维数组(y总喜欢)
//长度一般开到题目数据范围的2~3倍




// #include<iostream>
// #include<cstring>
// using namespace std;

// // 先确定N的两倍200000，再找大于200000的质数
// // 就是200003
// const int N=200003,null=0x3f3f3f3f;
// //null一定不在x范围内，
// //当等于这个数时表示这个位置上没人

// int h[N]; 

// int find(int x)
// //如果存在返回位置，如果不存在返回应该存储的位置
// {
//     int k=(x%N+N)%N;
//     while(h[k]!=null&&h[k]!=x)
//     {
//         k++;
//         if(k==N)
//             k=0;
//     }
//     return k; 
// }

// int main()
// {
//     int n;
//     scanf("%d",&n);
//     memset(h,0x3f,sizeof h);//全等于null
//     while(n--)
//     {
//         char op[2];
//         int x;
//         scanf("%s%d",op,&x); 
//         int k=find(x);
//         if(op[0]=='I')
//         {
//             h[k]=x;
//         }
//         else
//         {
//             if(h[k]!=null)
//                 puts("yes");
//             else
//                 puts("no");
//         }
//     }
// }

// // 我比较喜欢拉链法，好理解



// // 字符串哈希   超牛逼  
//以k进制的角度把一个字符串看成一个数字 
// //当需要快速判断2个字符串是否相等可用该方法

// // 字符串前缀哈希法
// str="ABCABCDEYXCACWING";
// h[0]=0;
// h[1]="A"的哈希值 
// h[2]="AB"的哈希值
// h[3]="ABC"的哈希值
// h[4]="ABCA"的哈希值

//  A B C D..Z  str[i]
// 可看成(1 2 3 4..26)p
        // ( 65 66 67 68..)p
// ①ABCD...一般不能映射成0，即str[i]是多少无所谓
// ②该哈希方式假定人品足够好不存在冲突
//     p=131或13331
//     Q=2^64
//     这么取的话基本不会出现冲突，一般都这么取

// "ABCD"=(1xp^3+2xp^2+3xp^1+4xp^0)mod Q
// h[i]=h[i-1] x p+str[i]

// 高位|-------------|---------|------------|低位
//     1            L         R

//             最高位          最低位
// h[R]        p^(R-1)         p^0
// h[L-1]      p^(L-1)         p^0
// h[L-1]x p^(R-L+1)与h[R]右端对齐

    // 1234564
    //   846
    //    ↓
    // 1234564
    //     846

// 最终公式:h[R]-h[L]x P^(R-L+1)
// 用unsigned long long来代替取模


// 字符串哈希题
#include<iostream>

using namespace std;

typedef unsigned long long ull;
const int N=100010,P=131;

int n,m;
char str[N];
ull h[N],p[N];//p数组用来存储p的多少次方
//h[]数组表示某个前缀的哈希值，
ull get(int l,int r)
{
    return h[r]-h[l-1] *p[r-l+1];
}




int main()
{
    scanf("%d%d%s",&n,&m,str+1);
    p[0]=1;//p^0=1
    //p[1]=1*131,p[2]=131*131,....
    for(int i=1;i<=n;i++)
    {
        p[i]=p[i-1]*P;
        h[i]=h[i-1]*P+str[i];
    }
    for(int i=1;i<=n;i++)
    {
        cout<<h[i];
        cout<<endl;
    }
    // while(m--)
    // {
    //     int l1,l2,r1,r2;
    //     scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
    //     if(get(l1,r1)==get(l2,r2))
    //         puts("yes");
    //     else
    //         puts("no");
    // }
    system("pause");
    return 0;
}