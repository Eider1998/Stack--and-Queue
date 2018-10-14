#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#define maxsize 10001
using namespace std;

typedef struct
{
    char *base;
    char *top;
    char *m;
    int stacksize;
} stack;

void InitStack(stack &s)
{
    s.base = (char *)malloc(maxsize * sizeof(char));
    if(!s.base)
    {
        exit(0);
    }

    s.top = s.base;
    s.m = s.top;//只能==s.top，因为s.bse分配了好大的空间
    s.stacksize = maxsize;
}

void push(stack &s, char e)
{
    if(s.top - s.base >= s.stacksize)
    {
        s.base = (char *)realloc(s.base, (s.stacksize + maxsize) * sizeof(char));
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
    char str[251];
    int i, n;

    while(gets(str) != NULL)
    {
        n = strlen(str);
        stack s;
        InitStack(s);
        for(i = 0; i < n; i++)
        {
            if(i == 0 && str[i] == '#')//好好看看这里
            {
               s.top = s.base;
            }

            else if(str[i] != '#' && str[i] != '@')
            {
                push(s, str[i]);
            }

            else if(str[i] == '#')
            {
                //--s.top;
                if(!EmptyStack(s))
                {
                    pop(s);
                }

            }

            else if(str[i] == '@')
            {
                s.top = s.base;
            }
        }

        while(s.top != s.m)
        {
            printf("%c", *s.m);//从栈底开始输出时
            s.m++;
        }

      // printf("%c", *s.m);
        printf("\n");
    }
    return 0;
}
