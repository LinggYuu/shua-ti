#include <stdio.h>
#include <stdlib.h>
 
int fun(int n){
    if(n <= 0)
        return 0;
    if(n == 1)
        return 1;
    if(n == 2)
        return 2;
    return fun(n-1)+fun(n-2);
}
 
int main()
{
    int N;
    printf("请输入楼梯层数：");
    scanf("%d",&N);
    printf("上楼方法共：%d种\n",fun(N));
 
    return 0;
}