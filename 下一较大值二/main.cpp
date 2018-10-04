#include<stdio.h>
#include<string.h>
#include<iostream>
#include<stack>
using namespace std;

int a[100001], b[100001], stacks[100001];

int main(void)
{
    int t, n, i, flag, top;

    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        flag = 0;
        top = 0;
        for(i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
        }

        b[n - 1] = -1;
        for(i = n - 2; i >= 0; i--)
        {
            flag = 0;
            if(a[i + 1] > a[i])
            {
                stacks[++top] = a[i + 1];
                b[i] = a[i + 1];
            }

            else
            {
                while(top != 0)
                {
                    if(stacks[top] > a[i])
                    {
                        b[i] = stacks[top];
                        flag = 1;
                        break;
                    }

                    top--;
                }

                if(!flag)
                {
                    b[i] = -1;
                }
            }

        }

        for(i = 0; i < n; i++)
        {
            printf("%d-->%d\n", a[i], b[i]);
        }

        if(t != 0)
        {
            printf("\n");
        }
    }

    return 0;
}
