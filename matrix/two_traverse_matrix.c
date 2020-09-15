//
// Created by 苏建辉 on 2020/9/3.
//
#include <stdio.h>
#include <stdbool.h>

int searchMatrix(int ** matrix, int matrixRowSize, int matrixColSize, int target) {

    // matrix 四个角中选取一个合适的角  左下角 向上递减 向右递增
    // clang 无法通过编译  ？？？？？
    int start_row = matrixRowSize > 1 ? matrixRowSize - 1 : 0 ;
    int start_col = 0;
    int res = 0;

    while(start_row >= 0 && start_col < matrixColSize){

        if(target < matrix[start_row][start_col] ){
            start_row--;
            continue;
        } else if( target > matrix[start_row][start_col] ){
            start_col++;
            continue;
        } else if(matrix[start_row][start_col] == target){
            res = 1;
            break;
        }

    }

    return res;

}


int main(void)
{
    int row = 5;
    int col = 5;
    int target = 22;
    int matrix[][5] = {
            {1,   4,  7, 11, 15},
            {2,   5,  8, 12, 19},
            {3,   6,  9, 16, 22},
            {10, 13, 14, 17, 24},
            {18, 21, 23, 26, 30}
    };

    printf("%d \n",searchMatrix((int **) matrix, row, col, target));
    return 0;

}

