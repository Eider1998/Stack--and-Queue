/********************************************
本题的基本操作都是沿用刚刚的，所以开辟空间时
还是用了char都没有发现导致浪费了太多时间
********************************************/

#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#define maxsize 100001
using namespace std;

typedef struct
{
    int *base;
    int *top;
    int stacksize;
} stack;

void InitStack(stack &s)
{
    s.base = (int *)malloc(maxsize * sizeof(int));
    if(!s.base)
    {
        exit(0);
    }

    s.top = s.base;
    s.stacksize = maxsize;
}

void push(stack &s, int e)
{
    if(s.top - s.base >= s.stacksize)
    {
        s.base = (int *)realloc(s.base, (s.stacksize + maxsize) * sizeof(int));

        if(!s.base)
        {
            exit(0);
        }
        s.top = s.base + s.stacksize;
        s.stacksize += maxsize;
    }

    *s.top++ = e;
}

void pop(stack &s)
{
    if(s.top == s.base)
    {
        exit(0);
    }

    else
    {
        s.top--;
    }
}

int EmptyStack(stack &s)
{
    if(s.top == s.base)
    {
        return 1;
    }

    else
    {
        return 0;
    }
}

int a[100001], b[100001];
int main(void)
{
    int flag, n, t, i;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        stack s;
       // char *p;

        InitStack(s);
        for(i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
        }

        b[n - 1] = -1;

        for(i = n - 2; i >= 0; i--)
        {
            flag = 1;
          //  p = s.top;
            if(a[i + 1] > a[i])
            {
                b[i] = a[i + 1];
                push(s, a[i + 1]);
            }

            else
            {

                while(!EmptyStack(s))
                {
                    //printf("%d\n", *(s.top - 1));
                    if(*(s.top - 1) > a[i])
                    {
                        //printf("%d %d$\n", *(s.top - 1), a[i]);
                        b[i] = *(s.top - 1);
                        //printf("%d %d$\n\n", a[i], b[i]);
                        //printf("%d\n\n", *p);
                        flag = 0;
                        break;//找到之后跳出循环！！
                    }

                    s.top--;
                }

                if(flag)
                {
                    b[i] = -1;
                }
            }

        }

        for(i = 0; i < n; i++)
        {
            printf("%d-->%d\n", a[i], b[i]);
        }

        if(t > 0)
        {
            printf("\n");
        }
    }

    return 0;
}
