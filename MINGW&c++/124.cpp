#include <iostream.h>
#include<stdlib.h>
#include<conio.h>
#include<stdio.h>
#define Bsize 4
typedef struct BLOCK//声明一种新类型——物理块类型
{
int pagenum;//页号
int accessed;//访问字段，其值表示多久未被访问
}BLOCK;
int pc;//程序计数器，用来记录指令的序号
int n;//缺页计数器，用来记录缺页的次数
static int temp[320];//用来存储320条随机数
BLOCK block[Bsize]; //定义一大小为4的物理块数组
//*************************************************************
void init( ); //程序初始化函数
int findExist(int curpage);//查找物理块中是否有该页面
int findSpace( );//查找是否有空闲物理块
int findReplace( );//查找应予置换的页面
void display ( );//显示
void suijishu( );//产生320条随机数,显示并存储到temp[320]
void pagestring( );//显示调用的页面队列
void OPT( );//OPT算法
void LRU( );// LRU算法
void FIFO( );//FIFO算法
//*************************************************************
void init( )
{
for(int i=0;i<Bsize;i++)
{
block[i].pagenum=-1;
block[i].accessed=0;
pc=n=0;
}
}
//-------------------------------------------------------------
int findExist(int curpage)
{
for(int i=0; i<Bsize; i++)
{
if(block[i].pagenum == curpage )
return i;//检测到内存中有该页面，返回block中的位置
}
return -1;
}
//-------------------------------------------------------------
int findSpace( )
{
for(int i=0; i<Bsize; i++)
{
if(block[i].pagenum == -1)
return i;//找到空闲的block，返回block中的位置
}
return -1;
}
//-------------------------------------------------------------
int findReplace( )
{
int pos = 0;
for(int i=0; i<Bsize; i++)
{
if(block[i].accessed >block[pos].accessed)
pos = i;//找到应予置换页面，返回BLOCK中位置
}
return pos;
}
//-------------------------------------------------------------
void display( )
{
for(int i=0; i<Bsize; i++)
{
if(block[i].pagenum != -1)
{ printf(" %02d",block[i].pagenum);}
}
cout<<endl;
}
//-------------------------------------------------------------
void suijishu( )
{ int flag=0;
cin>>pc;
cout<<"******按照要求产生的320个随机数：*******"<<endl;
for(int i=0;i<320;i++)
{
temp[i]=pc;
if(flag%2==0) pc=++pc%320;
if(flag==1) pc=rand( )% (pc-1);
if(flag==3) pc=pc+1+(rand( )%(320-(pc+1)));
flag=++flag%4;
printf(" %03d",temp[i]);
if((i+1)%10==0) cout<<endl;
}
}
//-------------------------------------------------------------
void pagestring( )
{
for(int i=0;i<320;i++)
{
printf(" %02d",temp[i]/10);
if((i+1)%10==0) cout<<endl;
}
}
//-------------------------------------------------------------
void OPT( )
{
int exist,space,position ;
int curpage;
for(int i=0;i<320;i++)
{
if(i%100==0) getch( );
pc=temp[i];
curpage=pc/10;
exist = findExist(curpage);
if(exist==-1)
{
space = findSpace ( );
if(space != -1)
{
block[space].pagenum = curpage;
display( );
n=n+1;
}
else
{
for(int k=0;k<Bsize;k++)
{
for(int j=i;j<320;j++)
{
if(block[k].pagenum!= temp[j]/10)
{
block[k].accessed = 1000;
}//将来不会用，设置为一个很大数
else
{
block[k].accessed = j;
break;
}
}
}
position = findReplace( );
block[position].pagenum = curpage;
display( );
n++;
}
}
}
cout<<"缺页次数:"<<n<<endl;
cout<<"缺页率:"<<(n/320.0)*100<<"%"<<endl;
}
//-------------------------------------------------------------
void LRU( )
{
int exist,space,position ;
int curpage;
for(int i=0;i<320;i++)
{
if(i%100==0) getch( );
pc=temp[i];
curpage=pc/10;
exist = findExist(curpage);
if(exist==-1)
{
space = findSpace( );
if(space != -1)
{
block[space].pagenum = curpage;
display( );
n=n+1;
}
else
{
position = findReplace( );
block[position].pagenum = curpage;
display( );
n++;
}
}
else block[exist].accessed = -1;//恢复存在的并刚访问过的BLOCK中页面accessed为-1
for(int j=0; j<4; j++)
{block[j].accessed++;}
}
cout<<"缺页次数:"<<n<<endl;
cout<<"缺页率:"<<(n/320.0)*100<<"%"<<endl;
}
//-------------------------------------------------------------
void FIFO( )
{
int exist,space,position ;
int curpage;
for(int i=0;i<320;i++)
{
if(i%100==0) getch( );
pc=temp[i];
curpage=pc/10;
exist = findExist(curpage);
if(exist==-1)
{
space = findSpace( );
if(space != -1)
{
block[space].pagenum = curpage;
display( );
n=n+1;
}
else
{
position = findReplace( );
block[position].pagenum = curpage;
display( );
n++;
block[position].accessed--;
}
}
for(int j=0; j<Bsize; j++)
block[j].accessed++;
}
cout<<"缺页次数:"<<n<<endl;
cout<<"缺页率:"<<(n/320.0)*100<<"%"<<endl;
}
//*************************************************************
void main( )
{
int select;
cout<<"请输入第一条指令号(0~320)：";
suijishu( );
cout<<"*****对应的调用页面队列*******"<<endl;
pagestring( );
do
{
cout<<"****************************************"<<endl;
cout<<"------1:OPT 2:LRU 3:FIFO 4:退出-----"<<endl;
cout<<"****************************************"<<endl;
cout<<" 请选择一种页面置换算法:";
cin>>select;
cout<<"****************************************"<<endl;
init( );
switch(select)
{
case 1:cout<<"最佳置换算法OPT:"<<endl;
cout<<"*****************"<<endl;
OPT( );
break;
case 2:cout<<"最近最久未使用置换算法LRU:"<<endl;
cout<<"**************************"<<endl;
LRU( );
break;
case 3:cout<<"先进先出置换算法FIFO:"<<endl;
cout<<"*********************"<<endl;
FIFO( );
break;
default: ;
}
}while(select!=4);
}