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
    int n, t, i, m, x, ans;
    char str[1001];

    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &m, &n);
        stack s;
        InitStack(s);
        ans = 0;
        for(i = 0; i < n; i++)
        {
            scanf("%s", str);
            if(str[0] == 'P')
            {
                scanf("%d", &x);

                if(ans < m)
                {
                    push(s, x);
                    ans++;
                }

                else
                {
                    printf("F\n");
                }

            }

            else if(str[0] == 'A')
            {
                if(EmptyStack(s))
                {
                    printf("E\n");
                }

                else
                {
                    printf("%d\n", *(s.top - 1));
                }
            }

            else if(str[0] == 'O')
            {
                if(EmptyStack(s))
                {
                    printf("E\n");
                }

                else
                {
                    printf("%d\n", *--s.top);
                    ans--;
                }
            }
        }

        if(t != 0)
        {
            printf("\n");
        }
    }

    return 0;
}
