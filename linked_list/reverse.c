#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
	int data;
	struct node * next;
};

struct linked_list {
	struct node * head;
	struct node * tail;
	int size;
};

struct linked_list * init_link_list(void)
{
	struct linked_list * ptr = (struct linked_list *)malloc(sizeof(struct linked_list));
	if( ptr != NULL){
		ptr->size = 0;
		ptr->head = ptr->tail = NULL;
		return ptr;
	} else {
		return NULL;
	}
};


bool add_node(struct linked_list * sl,int value)
{
	struct node * new_node = (struct node *)malloc(sizeof( struct node));
	if(new_node != NULL){
		
		new_node->data = value;
		new_node->next = NULL;
		
		if( sl->head == NULL ){
			sl->tail = new_node;
			sl->head = new_node;
		} else {
			sl->tail->next = new_node;
			sl->tail = new_node;
		}
		
		sl->size++;

		return true;
	}else{
		return false;	
	}
		
}

void show_linked_list(struct node * n)
{

	if(n == NULL){
		return;
	}
	
	printf("linked list start:");
	while(n != NULL)	
	{
		printf("->%d",n->data);
		n = n->next;
	}
	printf("\n");
}

/**
 * 原地反转单链表
 */
bool reverse_linked_list(struct linked_list * sl)
{
	
	if(sl->head == NULL){
		return false;
	}

	// 存档
	// 反转
	struct node * prev_node = NULL;
	struct node * cur_node_ptr = sl->head;	
	struct node * tmp;	

	while(cur_node_ptr != NULL){	
		
		
		tmp = cur_node_ptr->next;
		
		// 反转
		cur_node_ptr->next = prev_node;		
		
		// 存档
		prev_node = cur_node_ptr;
		cur_node_ptr = tmp;
		
	}
	
	tmp = sl->head;
	sl->head = sl->tail;
	sl->tail = tmp;

	return true;
}

int main(void)
{	
	// 构造单链表
	struct linked_list * sl;
	
	if( (sl = init_link_list()) == NULL){
		printf("init linked list error\n");
		exit(1);
	} else {
		printf("init linked list success , address is : %p \n",sl);
	}
	
	// 模拟数据	
	int i;
	int mock_data[9] = {1,2,3,4,5,6,7,8,9};
	for(i = 0;i<9;i++){
		if( !add_node(sl,mock_data[i]) ){
			printf("malloc new node fail \n");
			exit(1);
		}
	}
	show_linked_list(sl->head);
	
	// 反转单链表
	reverse_linked_list(sl);
	show_linked_list(sl->head);

}
