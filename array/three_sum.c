//
// Created by sujianhui on 8/19/20.
//

// leetcode.15 hree number sum

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

int three_sum(int * a,int len,int target)
{
    int i;
    int difference;
    int res_two;
    int res = -1;
    int con[100][2];


    for(i=0;i<len;i++)
    {
        if(a[i] < target){
            difference = target - a[i];
            res_two = two_sum(a,len,difference,con);

            if(res_two < 0){
                printf("not found \n");
            } else {
                res++;
                // limit effective answer length in buffer array.
                res_two = res_two + 1;
                for(int j = 0;j < res_two ;j++){
                    printf(" %d + [%d,%d] \n",a[i],con[i][0],con[i][1]);
                }
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
    var_dump(data,sizeof(data) / sizeof(int));

    three_sum(data,sizeof(data) / sizeof(int),8);

    puts("");
    return 0;
}