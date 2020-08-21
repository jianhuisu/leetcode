#include <stdio.h>

int coinChange(int * coins, int coin_size , int amount) {

    // 数组大小为 amount + 1，初始值也为 amount + 1
    int dp[amount + 1];
    int j;

    for(j = 0; j < amount + 1;j++){
        // INF is amount * 1 , we target is min , so set a INF value
        // 为啥 dp 数组初始化为 amount + 1 呢，因为凑成 amount 金额的硬币数最多只可能等于 amount
        // （全用 1 元面值的硬币），所以初始化为 amount + 1 就相当于初始化为正无穷，便于后续取最小值。
        dp[j] = amount + 1;
    }

    // base case
    dp[0] = 0;
    int index_coin;

    for (int i = 0; i < amount + 1; i++) {

        // 内层 for 在求所有子问题 + 1 的最小值
        index_coin = 0;
        while( index_coin < coin_size ){

            // 子问题无解，跳过  first , know if amount is 1 , need how many coins , next equal optimize amount 1 answer + 1
            if (i - coins[index_coin] < 0) {
                index_coin++;
                continue;
            }

            dp[i] = dp[ i - coins[index_coin] ]  + 1 > dp[i] ? dp[i] : dp[ i - coins[index_coin] ]  + 1;
            index_coin++;
        }
    }

    return dp[amount] == amount ?  -1 : dp[amount] ;
}

int main(void)
{
    int coins[3] = {1,2,5};
    int amount = 20;

    printf("value: %d \n",coinChange(coins,3,amount));
}