#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;

int main(void)
{
    char st;
    int top = -1, stack[10001];

    while(scanf("%c", &st) && st != '#')
    {
        if(st >= '0' && st <= '9')
        {
            stack[++top] = st - '0';
        }

        if(st == '+')
        {
            stack[top - 1] = stack[top] + stack[top - 1];
            top--;
        }

        if(st == '-')
        {
             stack[top - 1] = stack[top - 1] - stack[top];
             top--;
        }

        if(st == '*')
        {
             stack[top - 1] = stack[top] * stack[top - 1];
             top--;
        }

        if(st == '/')
        {
             stack[top - 1] = stack[top - 1] / stack[top];
             top--;
        }
    }

    printf("%d\n", stack[top]);

    return 0;

}
