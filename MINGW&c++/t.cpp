#include <stdio.h>
#include <dos.h>
#include <stdlib.h>
#include <conio.h>
#include <io.h>
#include <windows.h>

#define P_NUM 3
//根据进程建立函数可知，P_NUM是当前需要创建的节点数也就是进程数量。
#define P_TIME 50
//用于确定当前进程的权限（优先级）



enum state {/*枚举类型*/
	ready,//就绪
	execute,//执行
	block,//阻塞
	finish//完成（终止）
};
//该模块枚举了进程的各个状态，分别为就绪，执行，阻塞，完成


struct pcb {/*进程控制块数据结构*/
	char name[4];
	//进程的名称
	int priority;
	//进程的优先级，即是进程的权限
	int cputime;
	//占用cpu时间
	int needtime;
	//需要时间，指的是一个进程到结束所需的运行时间，
	//在以运行时间衡量优先级的调度算法中，该项数据相当重要。
	int count;
	//计数
	int round;
	//第几轮，也用来计数
	enum state process;
	//进程当前的状态
	struct pcb * next;
	//pcb的下一个节点指针，指向下一个节点的地址
};
//该结构体定义了pcb中含有的各项数据，当它被建立时代表一个进程被建立了


struct pcb * get_process();/*进程建立*/
struct pcb * get_process() {
	struct pcb *q;
	//结构体指针q，表示当前循环种的当前节点
	struct pcb *t;
	//结构体指针t，指向的是当前循环的当前节点但在下一层循环时，
	//它代表着那一层循环中当前节点q的上一个节点，即是t
	struct pcb *p;
	//结构体指针p，指向的是整条链表中的第一个结点
	int i = 0;
	//一个用于记录的变量，当i==P_NUM时，即已创建了P_NUM个pcb节点
	printf("input name and needtime, please input 3 processes\n");
	//要求输入进程的名称以及该进程需要的运行时间（服务时间）  
	while (i < P_NUM) {//P_NUM进程个数
		q = (struct pcb *)malloc(sizeof(struct pcb));
		//分配空间，为基本操作，占用的空间以后需释放
		scanf("%s", &(q->name));
		//要求输入pcb结构体中的进程名
		scanf("%d", &(q->needtime));
		//要求输入进程完成需要时间
		q->cputime = 0;//占用cpu时间
		q->priority = P_TIME - q->needtime;
		//P_TIME（50）-当前进程完成需要时间表示该进程的优先级
		//当该进程的需要时间越小时权限越大，属于静态优先级中的“进程对资源的需求”
		q->process = ready;
		//该进程的状态变为就绪状态，表示已经进入就绪队列
		q->next = NULL;
		//也是建立链表的一个步骤，意为将节点指向空，即最后的节点为空节点
		if (i == 0) {//当i为0时，即 将创建该链表中的第一个节点
			p = q;
			//因为创建的是第一个节点，所以当前指针q是首节点，
			//p指向q则p为该链表的第一个节点，在之后的循环中p不再发生改变
			t = q;
			//t指向q意为着t是当前循环的当前节点，在下一层循环时，q发生了变化
			//而t仍指向下一层循环的前一层循环即当前循环的当前节点
		}
		else {//在此时创建节点时该链表至少有一个节点
			t->next = q;//t即为上一层循环的当时的当前节点，而q在本层循环中是t的下一个节点
			t = q;
			//t又再次指向q，使得在下次循环中t仍以下次循环的当前节点的前一个节点的身
			//份出现，其实就是一个转移量，例:t=a;a=b;b=t;
		}
		i++;//使之前往下一层循环，是否结束while循环的判断值
	}/*while*/
	return p;
	//返回的是该链表第一个节点的地址，意味着链表的创建完成，即P_NUM个进程的创建完成
}

void  display(struct pcb *p) {
	//这是一个用于显示各个进程各项数据的函数，并没有什么好注释的
	printf("name    cputime    needtime    priority    state\n");
	while (p) {//当p不为空结点时执行
		printf("%s", p->name);
		printf("        ");
		printf("%d", p->cputime);
		printf("        ");
		printf("%d", p->needtime);
		printf("        ");
		printf("%d", p->priority);
		printf("        ");
		switch (p->process) {//根据状态输出状态名称，可用if判断替换
		case ready:
			printf("ready\n");
			break;
		case execute:
			printf("execute\n");
			break;
		case block:
			printf("block\n");
			break;
		case finish:
			printf("finish\n");
			break;
		}
		p = p->next;
		//指向下一个节点，就是输入下一个进程的各项数据，直到下个节点为空结束
	}
}

int process_finish(struct pcb *q) {         /*进程是否结束，当还有进程没有结束时返回0*/
	int bl = 1;
	while (bl&&q) {
		bl = bl && q->needtime == 0;
		//若bl为0则逻辑假不用看后面直接为0，为1逻辑真判断运行需求时间是否为0，
		//为0则赋给bl 0，否则赋1
		q = q->next;
		//指向q的下一个节点
	}
	//当出现q需要的运行时间为0时则bl的值为0
	return bl;
}

void cpuexe(struct pcb *q) {
//该函数是进程的执行具体方式，该函数判断的是q但用于执行的却是t
	struct pcb *t = q;//t为q，但它在该函数中仍然代表的是当q为q->next时的上一个节点t
	int max_priority = 0;
	//该变量表示当前进程中进程的最大权限，用于指示下个要执行的进程
	while (q) {//当q不为空结点时执行循环
		if (q->process != finish) {
			//状态不为完成时进入该判断内部
			q->process = ready;
			//将其状态改为就绪，即该进程已经从就绪队列中出队并执行过了
			//假如该进程未运行完成，它将进入就绪队列的末尾等待（FIFO）
			//并变为准备状态，等待下一次执行
			if (q->needtime == 0) {
			//进程完成还需要的时间为0，代表进程执行完成
				q->process = finish;//状态变为finish，无需再次进入就绪队列
			}
		}
		if (max_priority < q->priority&&q->process != finish) {
		//判断当前节点的优先级是否为最高优先级，并且其是否已经处于完成状态
		//当它的优先级大于最高优先级且未完成时
			max_priority = q->priority;//最高优先级的值被替换
			t = q;//同时t指向q地址
		}
		q = q->next;//q则指向下一个节点
	}
	if (t->needtime != 0) {
		//t此时为拥有最高优先级的进程，在其完成需要时间不为0即未完成时将执行该进程
		t->priority -= 3;
		//这里是动态优先级中的一个步骤，当前进程在执行时它的优先级会下降3，防止垄断处理机
		t->needtime--;
		//执行一次，完成所需要的时间会减去1
		t->process = execute;//标志，代表该进程处于执行状态
		t->cputime++;//记录该进程占用cpu的时间，多执行一次则多占用1
	}
}

void priority_cal() {     /*优先数调度*/
	struct pcb * p;
	//定义结构体指针
	int cpu = 0;
	//当前总的占用cpu时间
	p = get_process();
	//如说所说，创建一个链表，其实是创建P_NUM个进程
	while (!process_finish(p)) {
		//判断进程是否已经结束，再未结束前都要执行
		cpu++;//cpu使用时间+1
		printf("cputime:%d\n", cpu);
		//输出占用cpu时间
		cpuexe(p);
		//执行进程
		display(p);
		//显示当前各进程状态
		//sleep(5);//该项指进入休眠状态休眠5ms，需要头文件#include <windows.h>
		//并且函数写错，s应大写
		Sleep(5);
	}
	printf("All processes have finished,press any key to exit");
	getchar();//输入一个值但不显示
}

void display_menu() {
	//这个是主菜单
	printf("CHOOSE THE ALGORITHM:\n");
	printf("1 PRIORITY\n");
	printf("2 ROUNDROBIN\n");
	printf("3 EXIT\n");
}
struct pcb * get_process_round() {       /*轮转进程建立*/
	
	//该函数与上面的struct pcb * get_process()有许多相同
	
	struct pcb *q;
	//结构体指针q，表示当前循环种的当前节点，同上
	struct pcb *t;
	//结构体指针t，指向的是当前循环的当前节点但在下一层循环时，
	//它代表着那一层循环中当前节点q的上一个节点，即是t
	struct pcb *p;
	//结构体指针p，指向的是整条链表中的第一个结点
	int i = 0;
	//用于判断是否建了P_NUM个节点，即进程
	printf("input name and time,please input 3 processes\n");

	while (i < P_NUM) {
		q = (struct pcb *)malloc(sizeof(struct pcb));
		scanf("%s", &(q->name));
		//进程名
		scanf("%d", &(q->needtime));
		//进程完成需要时间
		q->cputime = 0;//占用cpu时间
		q->round = 0;//轮数
		q->count = 0;//计数器
		q->process = ready;//建立的进程全为就绪状态，即全部进入就绪队列
		q->next = NULL;//最后一个节点为空
		if (i == 0) {//创建第一个进程时
			p = q;//p为最终链表的第一个节点，指第一个进程
			t = q;//t为下层循环q的上一个节点
		}
		else {
			t->next = q;
			t = q;
		}//使得t为下层循环q的上一个节点
		i++;//循环次数加1
		    //全部同上面struct pcb * get_process()的步骤描述
	}  /*while*/
	return p;
	//返回一个链表有3个节点即为3个进程，p指向第一个节点地址
}
//时间片为2
void cpu_round(struct pcb *q) {   /*处理机轮转*/
	q->cputime += 2;
	//在这一轮中q进程占用cpu时间+2
	q->needtime -= 2;
	//占用cpu时间+2即为该进程完成所需时间-2
	if (q->needtime < 0) {
		q->needtime = 0;
		//防止溢出的，当q完成所需要的时间为0时标志其执行结束，
		//如果小于零代表时间片大于执行前q完成所需要的时间，也代表执行结束，needtime也赋为0
	}
	q->count++;//计数器加一，代表q节点即该进程执行的次数
	q->round++;//轮数加一，代表q节点即该进程在哪一个轮中
	//因为这里就绪队列只有一个，所以轮数和计数器是一样的，记录了没什么用
	//如果运用多级反馈队列调度算法，使得每个进程进入的下一轮的就绪队列的时间片大小不同
	//那就有记录的必要了
	q->process = execute;//状态为执行状态
}

struct pcb * get_next(struct pcb * k, struct pcb * head) {    /*返回没有结束的进程*/
	struct pcb * t;
	t = k;
	//先do是防止k空
	do {
		t = t->next;//一直指向其下一个节点，下一个进程
	} while (t && t->process == finish);//如果进程执行完成了则结束
	if (t == NULL) {//已经指到最后为空了
		t = head;//链表遍历结束后再次从head结点遍历
		while (t->next != k && t->process == finish) {
			t = t->next;
		}
	}
	return t;
}

void set_state(struct pcb *p) {
	while (p) {
		if (p->needtime == 0) {
			//如果该进程完成所需时间为0则代表完成
			p->process = finish;//状态变为完成

		}
		if (p->process == execute) {
		//如果p的状态时执行，当其从执行函数中出来即用完时间片后要进入下一个就绪队列
			p->process = ready;//状态改为就绪
		}
		p = p->next;//指向其下一个节点即下一个进程
	}
}

void display_round(struct pcb *p) {

	//用于显示各个进程的数据的函数，同上
	
	printf("NAME  CPUTIME  NEEDTIME  COUNT  ROUND  STATE\n");
	while (p) {
		printf("%s", p->name);
		printf("        ");
		printf("%d", p->cputime);
		printf("        ");
		printf("%d", p->needtime);
		printf("        ");
		printf("%d", p->count);
		printf("        ");
		printf("%d", p->round);
		printf("        ");
		switch (p->process) {
		case ready:
			printf("ready\n");
			break;
		case execute:
			printf("execute\n");
			break;
		case finish:
			printf("finish\n");
			break;
		}
		p = p->next;
	}
}

void round_cal() {         /*循环轮转调度*/
	struct pcb * p;
	struct pcb * r;
	//定义两个结构体指针
	int cpu = 0;
	//未开始时占用cpu为0
	p = get_process_round();
	//创建3个进程，为链表形式
	r = p;
	//r为运行的进程，p则是用来判断的
	while (!process_finish(p)) {

		cpu += 2;
		//每次执行总的cpu时间加2
		cpu_round(r);
		//表示该进程在本轮中的执行
		r = get_next(r, p);
		//指向r的下个节点
		printf("cpu %d\n", cpu);
		//输出总的占用cpu的时间
		display_round(p);
		//显示各个进程的数据
		set_state(p);
		//设置p的状态
		Sleep(5);//休眠状态同上
	}
	printf("All processes have finished,press any key to exit");
	getchar();
}

/* 主程序 */
int main() {
	int user_input;
	display_menu();
	scanf("%d", &user_input);
	switch (user_input) {
	case 1:priority_cal(); break;
	case 2:round_cal(); break;
	case 3:break;
	default:
		display_menu();
		scanf("%d", &user_input);
		break;
	}
    system("pause");
    return 0;
}
