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
    begin()/end() ++,--返回前驱和后继
    一个有序链表的前驱表示这个有序序列里前面一个数
    set/multiset
    insert()插入一个数
    find()查找一个数
    cout()返回某个数的个数
    erase()
        (1)输入是一个数x，删除所有x
        (2)输入一个迭代器，删除这个迭代器
        迭代器是一种检查容器内元素并遍历元素的数据类型
    lower_bound(x)返回大于等于x的最小的数的迭代器
    upper_bound()返回大于x的最小的数的迭代器
    map/multimap,把两个元素映射,字典
    insert()插入的数是一个pair
    erase()输入的参数是pair或者迭代器
    find()
    map<string,int>a;
    a["yazan"]=1;
    cout<<a["yazan"];--->1
    可以像数组一样用
            
// unordered_set,unordered_map,unordered_muliset,unodrdered_multimap,哈希表
    与上面的乐死，增删改查时间复杂度O(1)比上面的快
    不支持和排序有关的操作 lowerbound等

// bitset,压位
    bitset<10000>s, 长度为10000
    支持所有位运算
    支持[]取出某一位
    count()返回有多少个1
    any/none()
        判断是否至少有一个1/判断是否全为0
    每个字节存八位
    比正常布尔数组省八倍
    set(),把所有位置成1
    set(k,v)将第k位变成v
    reset()把所有位变成0
    flip()等价于~
    flip(k)把k位取反

忘了就去网上查