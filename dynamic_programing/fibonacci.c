#include <stdio.h>

static void init_mem(int * a,int n)
{
    int i = 0;
    for(i;i<n;i++){
        a[i] = 0;
    }
}

int fib(int N)
{
    int dp_table[30];
    init_mem(dp_table,30);

    dp_table[1] = 0;
    dp_table[2] = 1;
    int i;
    for(i = 3;i<=N;i++){
        dp_table[i] = dp_table[i-1] + dp_table[i-2];
    }

    return dp_table[N];
}

int main(void)
{

    int n = 10;
    printf(" F(%d) value is %d \n",n,fib(n));
	return 0;
}
