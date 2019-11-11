// 系统某一程序分配空间时所需时间
// 与申请空间大小无关，与申请次数有关
c++ reference
// vector,变长数组,倍增的思想
    size()/length(),返回元素个数，即长度
    empty(),是否为空
    front(),back()返回第一个数，最后一个数
    push_back()向vector最后插入一个数
    pop_back()把当前最后一个数删掉
    begin()end()
    第零个数，最后一个数的后一个，相当于a[0],a[a.size()]
    支持比较运算
    vector<int>a(4,3) 3333
    vector<int>b(3,4) 444
    a<b,以字典序判断大小

    pair<int ,int>
    可以存储一个二元组，两个变量类型可以任意
    pair<int ,string>p
    p.first,p.second
    支持比较运算，以first为第一关键字，以second为第二关键字
    p=make_pair(10,"yazan")
    p={10,"ling"}
    常用于存有两只不同属性的东西
    可以存三个不同属性的东西
    pair<int,pair<int,int>>p

// string,字符串,substr(),c_str()
    size()字母个数
    empty()
    clear()
    string a="abc"
    a+='c'
    a.substr(1,2)第一个变量起始位置，第二个变量长度
    若是第一个变量从0开始，则后一个又是截止位置前一个位置
    第二个变量超长就会输出到尾部
    第二个变量可省略效果如上
    a.c_str()字符a存储字符串的起始地址



// queue,队列，队尾入队头出
    size()
    empty()
    push()向队尾插入 一个元素
    front()返回队头元素
    back()返回队尾元素
    pop()弹出队头元素
    想要清空则
        q=queue<int>();重构造


// priority_queue,优先队列,默认是大根堆
    push()插入一个元素
    top()返回堆顶元素
    pop()弹出堆顶元素
    priority_queue<int>heap
    heap.push(-x)一种使其变为小根堆的技巧
    或者定义
        priority_queue<int,vector<int>,greater<int>>q;


// stack,栈,
push()栈顶插入元素
top()返回栈顶元素
pop()弹出栈顶元素

// dqueue,双端队列
加强版vector,但用的不是很多，因为很慢
size()
empty()
clear()
front()
back()
push_back()在队尾插入一个元素
pop_back()在队尾弹出一个元素
push_front()在队首插入一个元素
pop_front()在队首弹出一个元素
begin()/end()
支持随机选址

// set,map,multiset,multimap,基于平衡二叉树(红黑树),动态维护有序序列
    size()
    empty()
    clear()
    set/multiset
    insert()插入一个数
    find()查找一个数
    cout()返回某个数的个数
    erase()
        (1)输入是一个数x，删除所有x
        (2)输入一个迭代器，删除这个迭代器

// unordered_set,unordered_map,unordered_muliset,unodrdered_multimap,哈希表
// bitset,压位

