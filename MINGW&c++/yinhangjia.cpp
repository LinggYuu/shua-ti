#include <iostream>
using namespace std;
#define MAXPROCESS 50                        //最大进程数
#define MAXRESOURCE 100                      //最大资源数
int AVAILABLE[MAXRESOURCE];                  //可用资源数组
int MAX[MAXPROCESS][MAXRESOURCE];            //最大需求矩阵
int ALLOCATION[MAXPROCESS][MAXRESOURCE];     //分配矩阵
int NEED[MAXPROCESS][MAXRESOURCE];           //需求矩阵
int REQUEST[MAXPROCESS][MAXRESOURCE];        //进程需要资源数
bool FINISH[MAXPROCESS];                     //系统是否有足够的资源分配
int p[MAXPROCESS];                           //记录序列
int m,n;                                     //m个进程,n个资源
void Init();    //初始化变量
bool Safe();    //安全检测
void Bank();    //银行家算法
void showdata(int,int);    //显示输出系统信息
int main()
{
    Init();
    Safe();
    Bank();
    system("pause");
    return 0;
}


/*初始化变量*/
void Init()                
{
    int i,j;
    cout << "请输入进程的数目:";
    cin >> m;
    cout << "请输入资源的种类:";
    cin >> n;
    cout << "请输入每个进程最多所需的各资源数,按照" << m << "x" << n << "矩阵输入" << endl;
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            cin >> MAX[i][j];
    cout << "请输入每个进程已分配的各资源数,也按照" << m << "x" << n << "矩阵输入" << endl;
    for(i = 0; i < m; i++)
        for(j = 0; j < n; j++)
        {
            cin >> ALLOCATION[i][j];
            NEED[i][j] = MAX[i][j] - ALLOCATION[i][j];
            if(NEED[i][j] < 0)
            {
                cout << "您输入的第" << i+1 << "个进程所拥有的第" << j+1 << "个资源数错误,请重新输入:" << endl;
                j--;
                continue;
            }
        }
        cout << "请输入各个资源现有的数目:" << endl;
        for(i = 0; i < n; i++)
            cin >> AVAILABLE[i];
}


/*银行家算法*/
void Bank()               
{
    int i,cusneed,flag = 0;    //cousneed资源进程号
    char again;    //键盘录入一个字符用于判断是否继续请求资源
    while(1)
    {
        showdata(n,m);
        cout << endl;
        /*请求资源*/
        while(true)
        {
            cout << "请输入要申请资源的进程号(注:第1个进程号为0,依次类推)" << endl;
            cin >> cusneed;
            if (cusneed > m)
            {
                cout << "没有该进程，请重新输入" << endl;
                continue;
            }
            cout << "请输入进程所请求的各资源的数量" << endl;
            for(i = 0; i < n; i++)
                cin >> REQUEST[cusneed][i];
            for(i = 0; i < n; i++)
            {
                if(REQUEST[cusneed][i] > NEED[cusneed][i])    //如果用户选择的线程的第i个资源请求数＞该线程该资源所需的数量
                {
                    cout << "您输入的请求数超过进程的需求量!请重新输入!" << endl;
                    continue;
                }
                if(REQUEST[cusneed][i] > AVAILABLE[i])    //如果用户选择的线程的第i个资源请求数＞系统现有的第i个资源的数量
                {
                    cout << "您输入的请求数超过系统有的资源数!请重新输入!" << endl;
                    continue;
                }
            }
            break;
        }
        /*如果请求合理，那么开始银行家算法计算*/
        /*先将申请的资源进行分配*/
        for(i = 0; i < n; i++)
        {
            AVAILABLE[i] -= REQUEST[cusneed][i];            //系统可用资源减去申请了的
            ALLOCATION[cusneed][i] += REQUEST[cusneed][i];    //线程被分配的资源加上已申请了的
            NEED[cusneed][i] -= REQUEST[cusneed][i];        //线程还需要的资源减去已申请得到的
        }
        /*判断分配申请资源后的系统是否安全；如果不安全则将分配的申请资源还回系统*/
        if(Safe())    //AVAILABLE  ALLOCATION  NEED变动之后，是否会导致不安全
            cout << "同意分配请求!" << endl;
        else
        {
            cout << "您的请求被拒绝!" << endl;
            /*资源还回系统*/
            for(i = 0; i < n; i++)
            {
                AVAILABLE[i] += REQUEST[cusneed][i];
                ALLOCATION[cusneed][i] -= REQUEST[cusneed][i];
                NEED[cusneed][i] += REQUEST[cusneed][i];
            }
        }
        /*对进程的需求资源进行判断；是否还需要资源；即NEED数组是否为0*/
        for (i = 0; i < n; i++)
            if (NEED[cusneed][i] <= 0)
                flag++;
        if (flag == n)    //如果该进程各资源都已满足条件，则释放资源
        {
            for (i = 0; i < n; i++)
            {
                AVAILABLE[i] += ALLOCATION[cusneed][i];
                ALLOCATION[cusneed][i] = 0;
                NEED[cusneed][i] = 0;
            }
            cout << "线程" << cusneed << " 占有的资源被释放！" << endl;
            flag = 0;
        }
        for(i = 0; i < m; i++)    //分配好了以后将进程的标识FINISH改成false
            FINISH[i] = false;
        /*判断是否继续申请*/
        cout << "您还想再次请求分配吗?是请按y/Y,否请按其它键" << endl;
        cin >> again;
        if(again == 'y' || again == 'Y')
            continue;
        break;
    }
}


/*安全性算法*/
bool Safe() 
{
    int i, j, k, l = 0;
    int Work[MAXRESOURCE];    //工作数组
    /*工作数组赋值，与AVAILABLE数组相同*/
    for (i = 0; i < n; i++)
        Work[i] = AVAILABLE[i];
    /*FINISH数组赋值，初始为全部false*/
    for (i = 0; i < m; i++)
        FINISH[i] = false;    //FINISH记录每个进程是否安全
    while (l < m)    //正常的话，共执行m次
    {
        int init_index = l;
        for (i = 0; i < m; i++)
        {
            if (FINISH[i] == true)    //如果这个进程安全则继续下一个循环
                continue;
            for (j = 0; j < n; j++)
                if (NEED[i][j] > Work[j])
                    break;
            if (j == n)
            {
                FINISH[i] = true;
                for (k = 0; k < n; k++)
                    Work[k] += ALLOCATION[i][k];
                p[l++] = i;//记录进程号    
            }
            else    //如果超过继续循环下一个进程
                continue;
        }
        if (l==init_index)
        {
            cout << "系统是不安全的" << endl;
            return false;
        }
    }
    cout << "系统是安全的" << endl;
    cout << "安全序列:" << endl;
    for (i = 0; i < l; i++)
    {
        cout << p[i];
        if (i != l - 1)
            cout << "-->";
    }
    cout << endl;
    return true;
}


/*显示*/
void showdata(int n,int m)
{
    int i,j;
    cout << endl << "-------------------------------------------------------------" << endl;  
    cout << "系统可用的资源数为:    ";
    for (j = 0; j < n; j++)
        cout << "    " << AVAILABLE[j];         
    cout << endl << "各进程还需要的资源量:" << endl; 
    for(i = 0; i < m; i++)   
    {
        cout << "    进程" << i << ":";   
        for(j = 0; j < n; j++)
            cout << "     " << NEED[i][j];   
        cout << endl;   
    }   
    cout << endl << "各进程已经得到的资源量:    " << endl << endl;
    for (i = 0; i < m; i++)   
    {
        cout << "    进程" << i << ":";   
        for (j = 0; j < n; j++)
            cout << "     " << ALLOCATION[i][j];
        cout << endl;   
    }  
    cout << endl; 
}