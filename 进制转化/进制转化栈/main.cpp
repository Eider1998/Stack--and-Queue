#include<cstdio>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<stack>
#define maxsize 20000
using namespace std;

typedef struct
{
  int *base;
  int *top;
  int stacksize;

}Stack;

void InitStack(Stack *s)
{
   s-> base = (int *)malloc(maxsize * sizeof(int));
   if(!s-> base)
   {
     exit(0);
   }

   s-> top = s-> base;
   s-> stacksize = maxsize;

}

void push(Stack *s, int e)
{
   if(s-> top - s-> base >= s-> stacksize)
   {
     s-> base = (int *)realloc(s-> base, (s-> stacksize + maxsize) * sizeof(int));

     if(!s-> base)
     {
       exit(0);
     }
     s-> top = s-> base + s-> stacksize;
     s-> stacksize += maxsize;
   }
   *s-> top = e;
    s-> top++;
}

int pop(Stack *s)
{
   if(s-> top == s-> base)
   {
     return 0;
   }

  // e = *(--s-> top);
   return 1;
}
int StackEmpty(Stack *s)
{
   if(s-> top == s-> base)
   {
     return 1;
   }

   else
   {
     return 0;
   }
}

int  main(void)
{
   int n, x;
   Stack s;

   InitStack(&s);
   scanf("%d %d", &n, &x);
   if(n == 0)
   {
     printf("0\n");
   }

   while(n)
   {
     push(&s, n % x);
      n = n / x;
   }
   while(!StackEmpty(&s))
   {
     printf("%d",*--s.top);
     pop(&s);
   }

   printf("\n");

   return 0;
}


/*

#include <stdio.h>
#include <stdlib.h>
#define stackmax 10000     //存储空间初始分配量
#define stacknum 10000     //存储空间分配增量
typedef int ElemType;
typedef struct
{
    ElemType       *base;  //栈底指针
    ElemType       *top;   //栈顶指针
    int     stacksize;
} SqStack;
int InitStack(SqStack &S) // 构造一个空栈S
{
    S.base = (ElemType*) malloc (stackmax*sizeof(ElemType));
    if (! S.base)
        exit(0);                                        //存储分配失败
    S.top = S.base;//空栈条件
    S.stacksize = stackmax; //栈的存储空间初始分配量
    return 0;
}
int Push(SqStack &S , int e)// 插入元素e为新的栈顶元素(创建一个栈)
{
    if(S.top-S.base >= S.stacksize)// 当前存储空间已满，增加分配
    {
        {
            S.base = (ElemType *)realloc(S.base,(S.stacksize+stacknum)*sizeof(ElemType));
            if (! S.base ) exit(0); // 存储分配失败
            S.top = S.base + S.stacksize;
            S.stacksize += stacknum;  //增加存储容量
        }
    }*S.top++=e;
        return 0;
}
void conversion(SqStack &S, int n, int m)//进制转换
{
    int t;
    while (n)
    {
        t = n%m;
        n = n/m;
        Push(S, t);
    }
}
void putstack(SqStack &S)//出栈
{
    while(S.top>S.base)
    {
        printf("%d", *(S.top-1));
        S.top--;
    }
}
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    SqStack S;
    InitStack(S);
    conversion(S, n, m);
    putstack(S);
    return 0;
}
---------------------
作者：acher66
来源：CSDN
原文：https://blog.csdn.net/acher66/article/details/52056935?utm_source=copy
版权声明：本文为博主原创文章，转载请附上博文链接！
*/
