#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define STACKSIZE 10000
#include<iostream>
using namespace std;

typedef int element;

typedef struct
{
    element *base, *top, stacksize;
}stack;

void initialstack(stack &s)
{
    s.base = (element *)malloc(STACKSIZE * sizeof(element));
    if(!s.base)
    {
        exit(0);
    }

    s.top = s.base;
    s.stacksize = STACKSIZE;

}

void gettop(stack &s, element &e)
{
    if(s.top != s.base)
    {
        e = *(s.top--);
    }
}

void push(stack &s, int e)
{
    if(s.top - s.base >= s.stacksize)
    {
        s.base = (element *)realloc(s.base, 2 * STACKSIZE * sizeof(element));
        if(!s.base)
        {
            exit(0);
        }

        s.top = s.base + s.stacksize;
        s.stacksize += STACKSIZE;
    }

    *s.top = e;
    s.top++;
}

void pop(stack &s, element &e)
{
    if(s.top != s.base)
    {
        s.top--;
        e = *s.top;
    }
}

element stackempty(stack &s)
{
    return s.top == s.base ? 1: 0;
}

void clean(stack &s)
{
    s.top = s.base;
}

int q[100001], p[100001];
int main(void)
{
    stack s;
    initialstack(s);
    int n;

    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &p[i]);
    }

    int m;
    scanf("%d", &m);
    while(m--)
    {
        clean(s);
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &q[i]);
        }

        int a = 0, b = 0;

        while(a < n)
        {
            if(p[a] == q[b])
            {
                a++;
                b++;
            }

            else
            {
                push(s, p[a]);
                a++;
            }
        }

        int flag = 1;
        while(!stackempty(s))
        {
            int e;
            pop(s, e);
            if(e == q[b])
            {
                b++;
            }
            else if(e != q[b])
            {
                flag = 0;
                break;
            }
        }

        if(flag)
        {
            printf("yes\n");
        }

        else
        {
            printf("no\n");
        }
    }

    return 0;
}
