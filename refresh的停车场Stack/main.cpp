#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#define maxsize 200001
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
   // s.m = s.top;//只能==s.top，因为s.bse分配了好大的空间
    s.stacksize = maxsize;
}

void push(stack &s, long long e)
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

long long a[200001];
int main(void)
{
    int n, m, i, flag, ans, t;
    char str[100];
    long long x;
    while(~scanf("%d %d", &n, &m))
    {
        ans = 0;
        t = 0;
        flag = 1;
        stack s;
        InitStack(s);
        for(i = 0; i < m; i++)
        {
            scanf("%s", str);
            if(strcmp(str, "Add") == 0)
            {
                scanf("%lld", &x);

                if(ans < n)
                {
                    push(s, x);
                    ans++;
                }

                else
                {
                    a[++t] = x;
                }
            }

            else if(strcmp(str, "Out") == 0)
            {
                if(t == 0)
                {
                    flag = 0;
                }

                else
                {
                    t--;
                }

            }

            else if(strcmp(str, "Del") == 0)
            {
                if(EmptyStack(s))
                {
                    flag = 0;
                }

                else
                {
                    pop(s);

                    if(t != 0)
                    {
                        push(s, a[1]);
                    }
                }

            }
        }

        if(!flag)
        {
            printf("Error\n");
        }

        else
        {
            while(s.top != s.base)
            {
                printf("%lld\n", *--s.top);
            }
        }


    }
       return 0;
}
