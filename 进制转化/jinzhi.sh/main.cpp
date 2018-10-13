#include<cstdio>
#include<cstdlib>
#include<iostream>
#define maxsize 2000
using namespace std;

typedef struct
{
    int *base;
    int *top;
    int stacksize;
}stack;

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
        s.top = s.base + s.stacksize;
        s.stacksize += maxsize;
    }

    *(s.top++) = e;
}

void pop(stack &s)
{
    if(s.top == s.base)
    {
        exit(0);
    }

    s.top--;
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
int main(void)
{
    int n, x;
    stack s;

    scanf("%d %d", &n, &x);
    if(n == 0)
    {
        printf("0\n");
    }

    InitStack(s);
    while(n)
    {
        push(s, n % x);
        n = n / x;
    }

    while(!EmptyStack(s))
    {
        printf("%d", *--s.top);
    }

    printf("\n");
    return 0;
}
