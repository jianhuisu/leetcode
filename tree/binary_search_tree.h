//
// Created by sujianhui on 8/20/20.
//

#ifndef LEETCODE_BINARY_SEARCH_TREE_H
#define LEETCODE_BINARY_SEARCH_TREE_H

#include <stdbool.h>

typedef struct node_value{
    int score;
} Node_Value;

typedef struct node{
    Node_Value data;
    struct node * left;
    struct node * right;
}Node;

typedef struct binary_search_tree{
    Node * root;
    int size;
} BST;


BST * createTree();
bool insertNode(BST * ptree,Node_Value v);
bool deleteNode(BST * ptree,Node * node);
void traverseTree(BST * ptree);
bool destroyTree(BST * ptree);

Node *  createNode(Node_Value v);
bool addNode(Node * insert,Node * root);
bool isGreaterThan(Node_Value v1,Node_Value v2);
int getTreeDepthByPostOrderTraverse(Node * root);
void var_dump_bst(BST * ptree);

bool isEmpty(BST * ptree);
bool isFull(BST * ptree);
bool isEqual(Node_Value v1,Node_Value v2);
int getNodeLevel(BST * ptree,Node * seekNode);
bool isSameTree(BST * ptree_1,BST * ptree_2);
bool isValidBST(BST * ptree);
bool isInBST(Node_Value needle,Node * root);

#endif //LEETCODE_BINARY_SEARCH_TREE_H
