//
// Created by sujianhui on 8/20/20.
//

#include <stdio.h>
#include "./binary_search_tree.h"

int main(void)
{
    BST * ptree = createTree();
    if(ptree != NULL ){
        printf("init bst tree success\n");
    }

    // mock data
    //int score_list[10] = {5,3,8,2,4,7,9,1,6,8};
    int score_list[6] = {5,1,2,3,4,6,7,8,9};
    Node_Value v;

    for(int i = 0;i < 6;i++){
        v.score = score_list[i];
        if(insertNode(ptree,v)){
            printf(".");
        }
    }

    printf("mock success \n");
    printf("tree depth is : %d \n",getTreeDepthByPostOrderTraverse(ptree->root));
    var_dump_bst(ptree);

    return 0;
}