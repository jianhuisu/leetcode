//
// Created by sujianhui on 8/19/20.
//

// 给你一个数组和一个整数 target，可以保证数组中存在两个数的和为 target，请你返回这两个数的索引。
// 对于一个无序的数组，我们似乎什么技巧也没有，只能暴力穷举所有可能。(though we can use memorandum do some optimize)

#include <stdio.h>

void var_dump(int * a,int len)
{
    int i;
    for(i=0;i<len;i++)
    {
        printf(" %d ",a[i]);
    }

    puts("");
}

void sort(int * a,int len)
{
    // bubble  small -> big
    int i;
    int j;
    int tmp;

    for(j = len;j > 0 ;j--)
    {
        for(i = 0;i < j ;i++)
        {
            if( i+1 < j &&  a[i] > a[i+1]){
                tmp = a[i];
                a[i] = a[i+1];
                a[i+1] = tmp;
            }
        }
    }
}

// method.2 Use double pointer :eft pointer + right pointer
/**
 *
 * @param a     : array
 * @param len   : array length
 * @param target   : should sum result
 * @param res_container  a buffer used to save result
 * @return
 */
int two_sum(int * a, int len,int target,int res_container[][2])
{
    sort(a,len);

    int left = 0;
    int right = len - 1;
    int sum;
    int container_index = 0;
    int res = -1;

    while(left < right){
        sum = a[left] + a[right];
        if(sum > target){
            right--;
        } else if(sum < target) {
            left++;
        } else {
            // printf("double pointer : a[%d]=%d , a[%d]=%d \n",left,a[left],right,a[right]);
            res_container[container_index][0] = a[left];
            res_container[container_index][1] = a[right];
            container_index++;
            res++;
            left++;
        }

    }

    return res;
}

int violent_exhaustion(int * a, int len,int target)
{
    int i,j;
    int difference;
    int res = -1;

    for(j = 0;j < len; j++){
        difference = target - a[j];
        for(i = j + 1;i < len;i++){
             if(a[i] == difference){
                 printf("exhaustion:a[%d]=%d , a[%d]=%d \n",j,a[j],i,a[i]);
                 res = 1;
             }
        }
    }

    return res;
}

int main(void)
{
    int data[6] = {8,3,5,6,1,7};
    var_dump(data,sizeof(data) / sizeof(int));
    sort(data,sizeof(data) / sizeof(int));

    // method.1
    violent_exhaustion(data,sizeof(data) / sizeof(int),8);


    // method.2
    // !!! this array not init, can not direct use;
    int con[100][2];
    int res = two_sum(data,sizeof(data) / sizeof(int),8,con);

    if(res < 0){
        printf("not found \n");
    } else {
        for(int i = 0;i < res + 1 ;i++){
            printf("[%d,%d] \n",con[i][0],con[i][1]);
        }
    }


    return 0;
}