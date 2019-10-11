//二分  本质并不是单调性
bool check(int x) {/* ... */} // 检查x是否满足某种性质

// 区间[l, r]被划分成[l, mid]和[mid + 1, r]时使用：
int bsearch_1(int l, int r)//左红右绿,找靠右（满足绿最左）的点
{
    while (l < r)
    {
        int mid = l + r >> 1;
        if (check(mid)) r = mid;    // check()判断mid是否满足性质
        else l = mid + 1;           
        //无解返回从左往右第一个满足check的数的位置，x不存在的话一定大于x
    }  
    return l;
}
// 区间[l, r]被划分成[l, mid - 1]和[mid, r]时使用：
int bsearch_2(int l, int r)//左红右绿,找靠左（满足红最右）的点
{
    while (l < r)
    {
        int mid = l + r + 1 >> 1;//不加1若遇到l=r-1则死循环
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    return l;
}
//二分是一定有解的，无解与模板有关 


bool check(double x) {/* ... */} // 检查x是否满足某种性质

double bsearch_3(double l, double r)
{
    const double eps = 1e-6;   // eps 表示精度，取决于题目对精度的要求
    while (r - l > eps)
    {
        double mid = (l + r) / 2;
        if (check(mid)) r = mid;
        else l = mid;
    }
    return l;
}

作者：yxc
链接：https://www.acwing.com/blog/content/277/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。