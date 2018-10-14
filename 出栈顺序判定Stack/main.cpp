#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#define maxsize 10001
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
    if(s.base == s.top)
    {
        return 1;
    }

    else
    {
        return 0;
    }
}

int a[10001], b[10001];
int main(void)
{
    int n, t, i, j;

    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    scanf("%d", &t);
    while(t--)
    {
        stack s;
        InitStack(s);
        for(i = 0; i < n; i++)
        {
            scanf("%d", &b[i]);
        }

       i = 0;
       j = 0;

       while(i < n)
       {
           if(a[i] == b[j])
           {
               i++;
               j++;
           }

           else
           {
               push(s, a[i]);
               i++;
           }
       }

       while(!EmptyStack(s))
       {
           if(*--s.top != b[j])
           {
               break;
           }

           else
           {
               j++;
           }
       }

       if(EmptyStack(s))
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
