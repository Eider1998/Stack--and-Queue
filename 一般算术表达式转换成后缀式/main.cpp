#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cstring>
#define maxsize 2000
using namespace std;

typedef struct
{
    char *base;
    char *top;
    int stacksize;
}stack;

void InitStack(stack &s)
{
    s.base = (char *)malloc(maxsize * sizeof(char));
    if(!s.base)
    {
        exit(0);
    }

    s.top = s.base;
    s.stacksize = maxsize;
}

void push(stack &s, char e)
{
    if(s.top - s.base >= s.stacksize)
    {
        s.base = (char *)realloc(s.base, (s.stacksize + maxsize) * sizeof(char));
        s.top = s.base + s.stacksize;
        s.stacksize += maxsize;
    }

    *s.top++ = e;
}

int pop(stack &s)
{
    if(s.top == s.base)
    {
        return 0;
    }

    return 1;


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

    InitStack(s);//必须先初始化
    while(scanf("%c", &st))
    {
        if(st >= 'a' && st <= 'z')
        {
            printf("%c", st);
        }

        else if(st == '+' || st == '-')
        {
            if(!EmptyStack(s) && *(s.top - 1) != '(')
            {
                printf("%c", *--s.top);
            }
            push(s, st);
        }

        else if(st == '*' || st == '/')
        {
            if((!EmptyStack(s) && *(s.top - 1) != '(') && (*(s.top - 1) == '*' || *(s.top - 1) == '/'))
            {
                printf("%c", *--s.top);
            }

            push(s, st);
        }

        else if(st == '(')
        {
            push(s, st);
        }

        else if(st == ')')
        {
            while(!EmptyStack(s) && *(s.top - 1) != '(')
            {
               printf("%c", *--s.top);
               pop(s);
            }

            --s.top;
        }

        else if(st == '#')
        {
            while(!EmptyStack(s))
            {
                printf("%c", *--s.top);
                pop(s);
            }

            break;
        }
    }

    return 0;
}


