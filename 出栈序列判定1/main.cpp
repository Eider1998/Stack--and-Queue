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
    int n, t, flag, a[10001], b[10001], x, y;
    stack s;

    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    scanf("%d", &t);
    while(t--)
    {
        InitStack(s);
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &b[i]);
        }

        x = 0;
        y = 0;

        while(x < n)
        {
            if(a[x] == b[y])
            {
                x++;
                y++;
            }

            else
            {
                push(s, a[x]);
                x++;
            }
        }
        flag = 1;
        while(!EmptyStack(s))
        {
            if(*(s.top - 1) == b[y] && y < n)
            {
                pop(s);
                y++;
            }

            else
            {
                flag = 0;
                break;
            }
        }


        if(EmptyStack(s) && flag)
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
