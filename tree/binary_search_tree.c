//
// Created by sujianhui on 8/20/20.
//

#include "binary_search_tree.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

BST * createTree()
{
    BST * ptree = (BST *)malloc(sizeof(BST) * 1);

    if(ptree == NULL){
        printf("create Node error\n");
        exit(1);
    }

    ptree->size = 0;
    ptree->root = NULL;
    return ptree;

}

/**
 * one node must insert on one tree's left node.
 * @param ptree
 * @param v
 * @return
 */
bool insertNode(BST * ptree,Node_Value v)
{
    if(isFull(ptree)){
        return false;
    }

    if(isInBST(v,ptree->root)){
       return false;
    }

    Node * ptr = createNode(v);

    if(isEmpty(ptree)){
        ptree->root = ptr;
        ptree->size++;
        return true;
    } else {
        return addNode(ptr,ptree->root);
    }

}

//是一组元素的集合，也提供两种基本操作：Enqueue（入队）将元素添加到队尾，Dequeue（出队）从队头取出元素并返回。就像排队买票一样，先来先服务，先入队的人也是先出队的
// 变量head和tail是队头和队尾指针，head总是指向队头，tail总是指向队尾的下一个元素。
static Node * queue[512];
static int head = 0;
static int tail = 0;

static void repeat_space(int n){
    int i;
    for(i = 0;i<n;i++){
        printf(" ");
    }
}

static void enqueue(Node * p)
{
    queue[tail++] = p;
}

static Node * dequeue(void)
{
    return queue[head++];
}

static int is_empty(void)
{
    return head == tail;
}

/**
 *
 * @param ptree
 * @param depth
 *
 * con zui di ceng xiang shagn dao tui , zhe yang sheng qu da liang ji suan pian yi
 * 2^k - 1= N
 * [sujianhui@dev529 tree]$>gcc -g traverse_bst.c binary_search_tree.c -lm -std=c99
 */
void var_dump_bst(BST * ptree)
{

    int depth = getTreeDepthByPostOrderTraverse(ptree->root);
    // 二叉树的性质1 ： 在二叉树的第 i 层上最多有 2^(i-1)个 节点.
    // 我们已知树的深度 depth, 所以树的最高层上最多容纳 2^(depth- 1)个叶子节点.

    int leaf_num;
	leaf_num = (int)pow((double)2,(double)(depth - 1));

	// node position + space position
	int section_num = leaf_num * 2;

	// use an array mock a queue , avoid overflow
    if(section_num > 512){
        printf("overflow printf range \n");
        return;
    }

	printf("%d \n",leaf_num);

    enqueue(ptree->root);

	Node * tmp;
    int level = 1;
    int cur_level;

    double totalSpace = (double)(section_num * 5);
    int stepSpace  = (int)(totalSpace / pow((double)2,(double )level));

    printf(" %f %d \n",totalSpace,stepSpace);

    while(!is_empty()){

        tmp = dequeue();
        cur_level = getNodeLevel(ptree,tmp);

        if(cur_level != level){
            printf("\n");
            level = cur_level;
            stepSpace  = (int)(totalSpace / pow((double)2,(double )level));
        }

        repeat_space(stepSpace);
        printf("(%d) ",tmp->data.score);
        if(tmp->left != NULL){
            enqueue(tmp->left);
        }

        if(tmp->right != NULL){
            enqueue(tmp->right);
        }


    }

}

/**
 * get one node on which level in a BST
 * : think root at level one
 * @param ptree
 * @param seekNode
 * @return
 */
int getNodeLevel(BST * ptree,Node * seekNode)
{

    int level = 1;
    Node * cur_node = ptree->root;

    while( cur_node != NULL && !isEqual(cur_node->data,seekNode->data)){
        if(isGreaterThan(cur_node->data,seekNode->data)){
            cur_node = cur_node->left;
        } else {
            cur_node = cur_node->right;
        }
        level++;
    }

    return level;
}

int getTreeDepthByPostOrderTraverse(Node * root)
{

    int left_height;
    int right_height;
    int max;

    if(root != NULL){

        left_height = getTreeDepthByPostOrderTraverse(root->left);
        right_height = getTreeDepthByPostOrderTraverse(root->right);
        max = left_height > right_height ? left_height : right_height;
        return (max+1);

    } else {
        return 0;
    }

}

bool isFull(BST * ptree)
{
    return ptree->size > 100 ? true : false;
}

bool isEmpty(BST * ptree)
{
    return ptree->size == 0 ? true : false;
}

Node * createNode(Node_Value v)
{
    Node * ptr = (Node *)malloc(sizeof(Node) * 1);

    if(ptr == NULL){
        // can not continue crate node , maybe no space
        return NULL;
    }

    // init
    ptr->data = v;
    ptr->left = NULL;
    ptr->right = NULL;

    return ptr;
}

bool addNode(Node * insert,Node * root)
{
    if(isGreaterThan(insert->data,root->data)){

        if(root->right == NULL ){
            root->right = insert;
            return true;
        } else {
            return addNode(insert,root->right);
        }

    } else {

        if(root->left == NULL ){
            root->left = insert;
            return true;
        } else {
            return addNode(insert,root->left);
        }

    }

}

bool isGreaterThan(Node_Value v1,Node_Value v2)
{
     if(v1.score > v2.score){
         return true;
     } else {
         return false;
     }
}

bool isEqual(Node_Value v1,Node_Value v2)
{
    return v1.score == v2.score ? true : false;
}

bool isInBST(Node_Value v,Node * root)
{
    if( root == NULL ){
        return false;
    } else if(isEqual(v,root->data)) {
        return true;
    } else {
        if(isGreaterThan(v,root->data)){
            return isInBST(v,root->right);
        } else {
            return isInBST(v,root->left);
        }
    }
}
