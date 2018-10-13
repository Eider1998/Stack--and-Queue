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
#define stackmax 10000     //�洢�ռ��ʼ������
#define stacknum 10000     //�洢�ռ��������
typedef int ElemType;
typedef struct
{
    ElemType       *base;  //ջ��ָ��
    ElemType       *top;   //ջ��ָ��
    int     stacksize;
} SqStack;
int InitStack(SqStack &S) // ����һ����ջS
{
    S.base = (ElemType*) malloc (stackmax*sizeof(ElemType));
    if (! S.base)
        exit(0);                                        //�洢����ʧ��
    S.top = S.base;//��ջ����
    S.stacksize = stackmax; //ջ�Ĵ洢�ռ��ʼ������
    return 0;
}
int Push(SqStack &S , int e)// ����Ԫ��eΪ�µ�ջ��Ԫ��(����һ��ջ)
{
    if(S.top-S.base >= S.stacksize)// ��ǰ�洢�ռ����������ӷ���
    {
        {
            S.base = (ElemType *)realloc(S.base,(S.stacksize+stacknum)*sizeof(ElemType));
            if (! S.base ) exit(0); // �洢����ʧ��
            S.top = S.base + S.stacksize;
            S.stacksize += stacknum;  //���Ӵ洢����
        }
    }*S.top++=e;
        return 0;
}
void conversion(SqStack &S, int n, int m)//����ת��
{
    int t;
    while (n)
    {
        t = n%m;
        n = n/m;
        Push(S, t);
    }
}
void putstack(SqStack &S)//��ջ
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
���ߣ�acher66
��Դ��CSDN
ԭ�ģ�https://blog.csdn.net/acher66/article/details/52056935?utm_source=copy
��Ȩ����������Ϊ����ԭ�����£�ת���븽�ϲ������ӣ�
*/
