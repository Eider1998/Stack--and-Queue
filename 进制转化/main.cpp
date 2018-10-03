#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stack>
using namespace std;

int main(void)
{
    int n, r;
    stack<int>t;

    scanf("%d", &n);
    scanf("%d", &r);

    if(n == 0)
    {
        printf("0\n");
    }

    else
    {
        while(n > 0)
        {
            int z = n % r;
            t.push(z);
            n /= r;
        }

        while(!t.empty())
        {
            printf("%d",t.top());
            t.pop();
        }
    }

    printf("\n");

    return 0;
}

