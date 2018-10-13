#include<cstdio>
#include<cstdlib>
#include<cstring>
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
int main(void)
{
    char st;
    stack s;

    InitStack(s);
    while(scanf("%c", &st))
    {
        if(st >= '0' && st <= '9')
        {
            push(s, st - '0');
        }

        else if(st == '*')
        {
            *(s.top - 2) = (*(s.top - 1)) * (*(s.top - 2));
            pop(s);
        }

        else if(st == '/')
        {
            *(s.top - 2) = (*(s.top - 2)) / (*(s.top - 1));
            pop(s);
        }

        else if(st == '+')
        {
            *(s.top - 2) = (*(s.top - 1)) + (*(s.top - 2));
            pop(s);
        }


        else if(st == '-')
        {
            *(s.top - 2) = (*(s.top - 2)) - (*(s.top - 1));
            pop(s);
        }

        else if(st == '#')
        {
            printf("%d\n", *--s.top);
            break;
        }

    }

    return 0;
}
