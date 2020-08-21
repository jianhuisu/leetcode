#   Fibonacci

leetcode.50 : 按照 fibonacci 数列规则，求以 0,1 起始的 fibonacci 中,第N个数的值.
N 代表第 N 个位置0 < N < 30.

         { f(n) = n; 当 n = 1 或 2 
    f(n) { f(n) = -1 ; 当 n < 0
         { f(n) = f(n - 1) + f(n - 2) ; 当 n > 2 

## answer.1

    #include <stdio.h>
    #include <stdlib.h>
    
    int fib(int N)
    {
        if(N < 0){
            printf("\"can not match\" \n");
            exit(1);
        }	
        
        // base case : 确定 fibonacci 的两个起始数
        // 同时 也是 end condition
        if( N == 1 || N == 2){
            return N - 1;
        }
    
        return fib(N - 1) + fib(N - 2);
    }
    
    int main(void)
    {
        int n = 10;
        printf(" F(%d) value is %d \n",n,fib(n));
        return 0;
    }

un 

    F(10) value is 34 

check answer

     N       1        2       3       4       5       6       7       8       9       10
     f(N)    0        1       1        2      3       5        8      13      21      34

O(n^2)
     
## answer.2  optimize answer.1 

    #include <stdio.h>
    #include <stdlib.h>
    
    
    int c = 0;
    int memorandum[30];
    static void init_mem(int * a,int n)
    {
        int i = 0;
        for(i;i<n;i++){
            a[i] = 0;
        }
    }
    
    int fib(int N)
    {
        c++;
        if(N < 0){
            printf("\"can not match\" \n");
            exit(1);
        }	
        
        // base case : 确定 fibonacci 的两个起始数
        // 同时 也是 end condition
        if( N == 1 || N == 2){
            return N - 1;
        }
    
        if( memorandum[N] != 0 ){
            return memorandum[N];
        } else {
            memorandum[N] = fib(N - 1) + fib(N - 2);
            return memorandum[N];
        }
    
    }
    
    int main(void)
    {
        init_mem(memorandum,30);
        int n = 10;
        printf(" F(%d) value is %d \n",n,fib(n));
        printf(" cal fid function total : %d \n",c);
        return 0;
    }

O(n)

## answer.3  Dymic programing

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

O(n)