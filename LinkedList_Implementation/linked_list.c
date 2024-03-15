/********************************************
	Class: Data Structure and Algorithms, KECE208_02
		   2nd semester, 2022

	1st Project: List

	linked_list.c

	Name:ÃÖÁø¿ì
	StudentID:2019320011
	E-mail:ryan00102@naver.com

**********************************************/

#include "linked_list.h"
#include "string.h"
int list_exist;

/*
	@Function name: struct linked_list* create_list(int number_of_nodes, int list_type)
	@Parameters: 
	1. int number_of_nodes : determine how many nodes will be in the list
	2. int list_type : determine which type node will be made
	@Returns: address of linked_list value
	@Descriptions: 
	Allocate address of linked_list to new_list and initialize ADT values of linked_list list.
	According to the list_type, insert or push nodes with value(1 ~ number_of_nodes) in random order with no duplication.
	Finally, reset the global variable : list_exist value as 1 and return the list.
	@Error cases:
	1. If the input value : number_of_nodes is less than 1, print error message.
	2. If the global variable : list_exist is 1 ; a list already exists, then print error message.
	3. If the input value : list_type is not 0 or 1 : invalid list type, print error message.
 */

struct linked_list* create_list(int number_of_nodes, int list_type)
{
	int a[number_of_nodes];
	int i, j;
	int bFound;

	if (number_of_nodes < 1)
	{
		printf("Function create_list: the number of nodes is not specified correctly\n");
		return NULL;
	}
	if (list_exist == 1)
	{
		printf("Function create_list: a list already exists\nRestart a Program\n");
		exit(0);
	}
	if (list_type != 0 && list_type != 1)
	{
		printf("Function create_list: the list type is wrong\n");
		exit(0);
	}
	struct linked_list * new_list = (struct linked_list*)malloc(sizeof(struct linked_list));
	new_list->head = NULL;
	new_list->tail = NULL;
	new_list->number_of_nodes = 0;
	new_list->type_of_list = list_type;

	//now put nodes into the list with random numbers.
	srand((unsigned int)time(NULL));
	if (list_type == 0)
	{
		for (i = 0; i < number_of_nodes; ++i)
		{
			while (1)
			{

				a[i] = rand() % number_of_nodes + 1;
				bFound = 0;
				for (j = 0; j < i; ++j)
				{
					if (a[j] == a[i])
					{
						bFound = 1;
						break;
					}
				}
				if (!bFound)
					break;
			}
			struct linked_node* new_node = create_node(a[i]);
			insert_node(new_list, new_node);
		}
	}
	else if (list_type == 1)
	{
		for (i = 0; i < number_of_nodes; ++i)
		{
			while (1)
			{

				a[i] = rand() % number_of_nodes + 1;
				bFound = 0;
				for (j = 0; j < i; ++j)
				{
					if (a[j] == a[i])
					{
						bFound = 1;
						break;
					}
				}
				if (!bFound)
					break;
			}
			struct linked_node* new_node = create_node(a[i]);
			push_Stack(new_list, new_node);
		}
	}
	list_exist = 1;
	printf("List is created!\n");
	return new_list;
}

/*
	@Function name:remove_list
	@Parameters:
	1. struct linked_list* list : the list going to be removed
	@Returns:No return value
	@Descriptions:Allocate address for deletenode and free deletenode by moving list->head
	@Error cases:There is no error case in this function
 */

void remove_list(struct linked_list* list)
{
	//your code starts from here
	int count = 0;
	int deletevalue = -1;
	struct linked_node* deletenode = (struct linked_node*)malloc(sizeof(struct linked_node));
	while (list->number_of_nodes > 0) {
		deletevalue = list->head->value; 
		deletenode = list->head;
		if (list->number_of_nodes != 1) {
			list->head->next->prev = NULL;
			list->head = list->head->next;
			list->number_of_nodes--;
			free(deletenode);
		}
		else {
			list->number_of_nodes--;
			free(deletenode);
		}
		printf("The node with value %d is deleted!\n", deletevalue);
		count++;
	}


	free(list);
	list_exist = 0;
	printf("The list is completely deleted: %d nodes are deleted\n", count);

	
}

/*
	@Function name: struct linked_node* create_node(int node_value)
	@Parameters: 
	1. int node_value : the integer value that a new node has
	@Returns: address of linked_node
	@Descriptions: Allocate address for node pointer, and initialize ADT values of linked_node.
	@Error cases: There is no error case.
 */

struct linked_node* create_node(int node_value)
{
	struct linked_node* node = (struct linked_node*)malloc(sizeof(struct linked_node));
	node->value = node_value;
	node->next = NULL;
	node->prev = NULL;
	return node;
}

/*
	@Function name: void insert_node(struct linked_list* list, struct linked_node* node)
	@Parameters: 
	1. struct linked_list* list : the list where the new node would be inserted
	2. struct linked_node* node : inserting node
	@Returns: No return value
	@Descriptions: Divide cases into 
	1) If there is no node in the list, head and tail of the list points the inserting node.
	2) If there is one node in the list. inserting node is connected to an existing node, 
	and head of the list points the node.
	3) Otherwise, connect the inserting node to existing nodes and head of the list points the node.
	Then, increase number_of_nodes by one, and reset type_of_list to 0.
	@Error cases: There is no error case.
 */

void insert_node(struct linked_list* list, struct linked_node* node)
{
	node->next = NULL;
	node->prev = NULL;

	if (list->head == NULL)		//if head is NULL, tail is also NULL.
	{
		list->head = node;
		list->tail = node;
		list_exist = 1;
	}
	else if (list->head == list->tail)
	{
		node->next = list->head;
		list->head->prev = node;
		list->head = node;
	}
	else if (list->head != list->tail)
	{
		node->next = list->head;
		list->head->prev = node;
		list->head = node;
	}
	(list->number_of_nodes)++;
	list->type_of_list = 0;
}


/*
	@Function name:remove_node
	@Parameters:
	1. struct linked_list* list : the list where the existing node would be deleted
	2. int rm_node_value : the integer value that the node going to be deleted has as value
	@Returns:No return value
	@Descriptions: rm_node has address for node that have rm_node_value as value. 
	Divide in 2 cases : 1. rm_node is head of list / 2. otherwise
	@Error cases:
	1. If list is stack, print error message 
	2. If there is no such node that have rm_node_value, print error message
 */

void remove_node(struct linked_list* list, int rm_node_value)
{
	//your code starts from here 
	struct linked_node* rm_node = NULL;
	struct linked_node* temp = list->head;
	if (list->type_of_list == 1) {
		printf("Function remove_node: The list type is not normal.Removal is not allowed\n");
		return;
	}
	else {
		for (int i = 0; i < list->number_of_nodes; i++) {
			if (temp->value == rm_node_value) {
				rm_node = temp;
				break;
			}
			else {
				temp = temp->next;
			}
		}
	}
	if (rm_node != NULL) {
		if (list->number_of_nodes == 1) {
			list->number_of_nodes = 0;
			remove_list(list);
		}
		else {
			if (rm_node == list->head) {
				list->head->next->prev = NULL;
				list->head = list->head->next;
				free(rm_node);
				list->number_of_nodes--;
			}
			else if (rm_node == list->tail) {
				list->tail->prev->next = NULL;
				list->tail = list->tail->prev;
				free(rm_node);
				list->number_of_nodes--;
			}
			else {
				rm_node->prev->next = rm_node->next;
				rm_node->next->prev = rm_node->prev;
				free(rm_node);
				list->number_of_nodes--;
			}
		}
		
	}
	else {
		printf("Function remove_node: There is no such node to remove");
		return;
	}

}

/*
	@Function name: void delete_range(struct linked_list* list, int id_1, int id_2)
	@Parameters:
	1. struct linked_list* list : the list that delete_range operation would be held
	2. int id_1, int id_2 : two integer values that determine range of deletion
	@Returns: No return value
	@Descriptions:
	Use check_1 and check_2 to find if there are two nodes with id_1 and id_2.
	Use position_1 and position_2 to confirm that range order is correct.
	start_node has an address of the node with id_1 integer value by using temp pointer.
	arr has the integer values of nodes between the node with id_1 and id_2.
	Use remove_node function to delete each node in the range.
	@Error cases:
	1. If the node with id_1 is behind the node with id_2 : order is destroyed, print error message
	2. If there is no node with id_1 integer value or id_2, print error message.
 */
void delete_range(struct linked_list* list, int id_1, int id_2)
{
	//your code starts from here
	int check_1 = 0, check_2 = 0;
	int position_1 = 0, position_2 = 0;
	int size = 0;
	struct linked_node* temp = list->head;
	struct linked_node* start_node = NULL;
	for (int i = 0; i < list->number_of_nodes; i++) {
		if (temp->value == id_1) {
			check_1 = 1;
			start_node = temp;
		}
		else {
			temp = temp->next;
			position_1++;
		}
	}
	temp = list->head;
	for (int i = 0; i < list->number_of_nodes; i++) {
		if (temp->value == id_2) {
			check_2 = 1;
		}
		else {
			temp = temp->next;
			position_2++;
		}
	}
	if (check_1 == 0 || check_2 == 0) {
		printf("Function delete range: the node does not exist");
		return;
	}
	else {
		if (position_1 > position_2) {
			printf("Function delete_range: the selected range of nodes is not in order");
			return;
		}
		else{
			size = position_2 - position_1 + 1;
			int* arr = (int*)calloc(size, sizeof(int));
			temp = start_node;
			for (int i = 0; i < size; i++) {
				arr[i] = temp->value;
				temp = temp->next;
			}
			for (int i = 0; i < size; i++) {
				remove_node(list, arr[i]);
			}
		}
	}


}

/*
	@Function name:push_Stack(struct linked_list* list, struct linked_node* node)
	@Parameters:
	1. struct linked_list* list : the list that a new node would be pushed in
	2. struct linked_node* node : the node going to be pushed
	@Returns:No return value
	@Descriptions: If list is empty, connect head and tail of the list to the node. 
	Otherwise, just connect tail of the list to the node.
	@Error cases:
	1. If list is not stack, print error message.
 */
void push_Stack(struct linked_list* list, struct linked_node* node)
{
	//your code starts from here
	node->prev = NULL;
	node->next = NULL;
	if (list->type_of_list != 1) {
		printf("Function push_Stack : The list type is not a stack");
		return;
	}
	if (list->head == NULL) {
		list->head = node;
		list->tail = node;
		list_exist = 1;
	}
	else if (list->head == list->tail) {
		node->prev = list->tail;
		list->head->next = node;
		list->tail = node;
	}
	else if (list->head != list->tail) {
		node->prev = list->tail;
		list->tail->next = node;
		list->tail = node;
	}
	(list->number_of_nodes)++;
}

/*
	@Function name:void pop_Stack(struct linked_list* list, int number)
	@Parameters:
	1. struct linked_list* list : the list where some nodes are going to be popped
	2. int number : determine how many nodes are going to be popped.
	@Returns:No return value
	@Descriptions: Allocate the deletenode address of tail of the list. 
	If there is no more node after pop, remove list after pop the nodes. 
	Otherwise, just pop the node by moving the tail pointer of the list.
	@Error cases:
	1. The list is normal list. 
	2. Number of deleting node is less than 1. 
	3. Number of deleting node exceeds the number of nodes list have.
 */
void pop_Stack(struct linked_list* list, int number)
{
	//your code starts from here
	struct linked_node* deletenode;
	if (list->type_of_list != 1) {
		printf("Function pop_Stack : The list type is not a stack");
		return;
	}
	else {
		if (number < 1) {
			printf("Function popStack: The number of nodes which will be removed is more than 1");
			return;
		}
		else {
			if (number > list->number_of_nodes) {
				printf("Function popStack: The number of nodes which will be removed is more than that in the stack");
				return;
			}
			else if (number == list->number_of_nodes) {
				list->number_of_nodes = 0;
				remove_list(list);
			}
			else {
				for (int i = 1; i <= number; i++) {
					if (list->number_of_nodes == 1) {
						deletenode = list->tail;
						deletenode->prev->next = NULL;
						list->tail = deletenode->prev;
						free(deletenode);
						list->number_of_nodes--;
						free(list);
					}
					else {
						deletenode = list->tail;
						deletenode->prev->next = NULL;
						list->tail = deletenode->prev;
						free(deletenode);
						list->number_of_nodes--;
					}
				}
			}
		}
	}

}

/*
	@Function name:void search_node(struct linked_list* list, int find_node_value)
	@Parameters:
	1. struct linked_list* list : the list that search operation would be held.
	2. int find_node_value : the value that the node going to be searched has
	@Returns:No return values. Just print where the value is.
	@Descriptions:A temp pointer traverse the list. 
	If there is the node with find_node_value, reset the node_exist as 1 and print the location of the node.
	@Error cases:
	1. If there is no node with find_node_value, print error message.
 */

void search_node(struct linked_list* list, int find_node_value)
{
	//your code starts from here
	struct linked_node* temp;
	int order = 0;
	int node_exist = 0;
	for (temp = list->head; temp != NULL; temp = temp->next) {
		order++;
		if (temp->value == find_node_value) {
			printf("The order of %d is %d.", find_node_value, order);
			node_exist = 1;
			break;
		}
	}
	if (node_exist != 1) {
		printf("¡°Function search_node : There is no such node to search.");
		return;
	}
}

/*
	@Function name: void swap_nodes(struct linked_list* list, int node1, int node2)
	@Parameters: 
	1. struct linked_list* list : the list that swap operation would be held.
	2. int node1, int node2 : two values that two nodes going to be swapped have as value
	@Returns: No return value
	@Descriptions: Using a temp pointer, allocate address having node1 as value to first pointer and 
	address having node2 as value to second pointer. 
	And divide cases according to whether each pointer is head or tail of the list or not.
	Additionally, divide cases according to whether two pointers are adjacent for each cases.
	@Error cases:
	1. If the number of node in the list is less than 2, print error message.
	2. If the list does not have all the integer parameter value in the list, print error message.
	3. If two integer parameter values(node1, node2) are same, there is nothing to swap, so print error message.
*/
void swap_nodes(struct linked_list* list, int node1, int node2)
{
	//your code starts from here
	
	struct linked_node *temp = list->head;
	struct linked_node *first = NULL;
	struct linked_node *second = NULL;
	int find1 = 0;
	int find2 = 0;
	if (list->number_of_nodes < 2) {
		printf("Function swap_nodes: The list size is smaller than 2, there is nothing to swap");
		return;
	}
	while (1 && find1 < list->number_of_nodes) {
		if (temp->value == node1) {
			first = temp;
			break;
		}
		temp = temp->next;
		find1++;
	}
	temp = list->head;
	while (1 && find2 < list->number_of_nodes) {
		if (temp->value == node2) {
			second = temp;
			break;
		}
		temp = temp->next;
		find2++;
	}
	if (first == NULL || second == NULL) {
		printf("Function swap_nodes: either one of the nodes is not available");
		return;
	}
	if (node1 == node2) {
		printf("Function swap_nodes: The node numbers are the same. Nothing to swap");
		return;
	}
	if (first == list->head && second != list->tail) {
		if (first->next == second) {
			second->next->prev = first;
			first->next = second->next;
			second->prev = NULL;
			second->next = first;
			first->prev = second;
			list->head = second;
		}
		else {
			struct linked_node *nextsecond = second->next;
			struct linked_node *prevsecond = second->prev;

			first->next->prev = second;
			second->prev->next = first;
			second->next->prev = first;
			second->next = first->next;
			second->prev = NULL;
			list->head = second;
			first->prev = prevsecond;
			first->next = nextsecond;
		}
	}
	else if (second == list->head && first != list->tail) {
		if (second->next == first) {
			first->next->prev = second;
			second->next = first->next;
			first->prev = NULL;
			first->next = second;
			second->prev = first;
			list->head = first;
		}
		else {
			struct linked_node *nextfirst = first->next;
			struct linked_node *prevfirst = first->prev;

			second->next->prev = first;
			first->prev->next = second;
			first->next->prev = second;
			first->next = second->next;
			first->prev = NULL;
			list->head = first;
			second->prev = prevfirst;
			second->next = nextfirst;
		}
	}
	else if (second == list->tail && first != list->head) {
		if (first->next == second) {
			first->prev->next = second;
			second->prev = first->prev;
			first->next = NULL;
			first->prev = second;
			second->next = first;
			list->tail = first;
		}
		else {
			struct linked_node *nextfirst = first->next;
			struct linked_node *prevfirst = first->prev;

			second->prev->next = first;
			first->prev->next = second;
			first->next->prev = second;
			first->prev = second->prev;
			first->next = NULL;
			list->tail = first;
			second->prev = prevfirst;
			second->next = nextfirst;
		}
	}
	else if (first == list->tail && second != list->head) {
		if (second->next == first) {
			second->prev->next = first;
			first->prev = second->prev;
			second->next = NULL;
			second->prev = first;
			first->next = second;
			list->tail = second;
		}
		else {
			struct linked_node *nextsecond = second->next;
			struct linked_node *prevsecond = second->prev;

			first->prev->next = second;
			second->prev->next = first;
			second->next->prev = first;
			second->prev = first->prev;
			second->next = NULL;
			list->tail = second;
			first->prev = prevsecond;
			first->next = nextsecond;
		}
	}
	else if (first == list->head && second == list->tail) {
		if (first->next == second) {
			first->prev = second;
			second->next = first;
			first->next = NULL;
			second->prev = NULL;
			list->head = second;
			list->tail = first;
		}
		else {
			first->next->prev = second;
			second->prev->next = first;
			list->head = second;
			list->tail = first;
			first->prev = second->prev;
			second->next = first->next;
			first->next = NULL;
			second->prev = NULL;
		}
	}
	else if (second == list->head && first == list->tail) {
		if (second->next == first) {
			second->prev = first;
			first->next = second;
			second->next = NULL;
			first->prev = NULL;
			list->head = first;
			list->tail = second;
		}
		else {
			second->next->prev = first;
			first->prev->next = second;
			list->head = first;
			list->tail = second;
			second->prev = first->prev;
			first->next = second->next;
			second->next = NULL;
			first->prev = NULL;
		}
	}
	else {
		if (first->next == second) {
			first->prev->next = second;
			second->next->prev = first;
			first->next = second->next;
			second->prev = first->prev;
			second->next = first;
			first->prev = second;
		}
		else if (second->next == first) {
			second->prev->next = first;
			first->next->prev = second;
			second->next = first->next;
			first->prev = second->prev;
			first->next = second;
			second->prev = first;
		}
		else {
			struct linked_node *nextfirst = first->next;
			struct linked_node *prevfirst = first->prev;

			first->prev->next = second;
			first->next->prev = second;
			first->next = second->next;
			first->prev = second->prev;
			second->prev->next = first;
			second->next->prev = first;
			second->next = nextfirst;
			second->prev = prevfirst;
		}
	}
}

/*
	@Function name:void forward_by_one(struct linked_list* list)
	@Parameters:
	1. struct linked_list* list : the list that forward_by_one operation would be held
	@Returns:No return values
	@Descriptions: Just move the head and tail pointer forward rather than move all nodes in the list.
	@Error case:If the number of node in the list is less that 2, print error message.
*/
void forward_by_one(struct linked_list* list)
{
	//your code starts from here
	if (list->number_of_nodes < 2) {
		printf("Function forward_by_one: The list size is smaller than 2, there is nothing to rotate");
		return;
	}
	else {
		if(list->type_of_list != 0){
			printf("Function forward_by_one: The list type is not normal");
			return;
		}
		else {
			list->tail->next = list->head;
			list->head->prev = list->tail;
			list->tail = list->head;
			list->head = list->head->next;
			list->head->prev = NULL;
			list->tail->next = NULL;
		}
	}
}

/*
	@Function name:void backward_by_one(struct linked_list* list)
	@Parameters:
	1. struct linked_list* list : the list that backward_by_one operation would be held
	@Returns:No return value
	@Descriptions:Just move the head and tail pointer forward rather than move all nodes in the list.
	@Error cases:If the number of node in the list is less that 2, print error message.
*/
void backward_by_one(struct linked_list* list)
{
	//your code starts from here
	if (list->number_of_nodes < 2) {
		printf("Function backward_by_one: The list size is smaller than 2, there is nothing to rotate");
		return;
	}
	else {
		if (list->type_of_list != 0) {
			printf("Function backward_by_one: The list type is not normal");
			return;
		}
		else {
			list->tail->next = list->head;
			list->head->prev = list->tail;
			list->head = list->tail;
			list->tail = list->tail->prev;
			list->head->prev = NULL;
			list->tail->next = NULL;
		}
	}
}

/*
	@Function name: void reverse_range(struct linked_list* list, int order1, int order2)
	@Parameters: 
	1. struct linked_list* list : the list that reverse_range operation would be held
	2. int order1, int order2 : determine range of nodes going to be arranged reversely
	@Returns: No return value
	@Descriptions: Make array that will contains values of the nodes going to be arranged reversely.
	Using a next pointer to reach the node located in order1 in the list.
	Assign the values of the nodes going to be arranged reversely into the array.
	Swap the nodes from both ends, using swap_nodes function.
	@Error cases:
	1. If order1 is larger than order2, print error message.
	2. If order2 exceeds the number of nodes in the list, print error message.
	3. If order1 is smaller than 0, print error message.
*/

void reverse_range(struct linked_list* list, int order1, int order2)
{
	//your code starts from here
	int size = order2 - order1 + 1;
	struct linked_node* firstnode = list->head;
	int* arr = (int*)calloc(size, sizeof(int));
	if (order1 > order2 || order2 > list->number_of_nodes || order1 <= 0) {
		printf("Function reverse_range: Input value is invalid");
		return;
	}
	int count = 1;
	while (count < order1) {
		firstnode = firstnode->next;
		count++;
	}
	for (int i = 0; i < size; i++) {
		arr[i] = firstnode->value;
		
		if (firstnode == list->tail) {
			break;
		}
		firstnode = firstnode->next;
	}
	for (int i = 0; i < size/2 ; i++) {
		swap_nodes(list, arr[i], arr[size - 1 - i]);
	}
	
	
	

}

/*
	@Function name: void powerofN_reverse(struct linked_list* list, int n)
	@Parameters:
	1. struct linked_list* list : the list where this function would be held.
	2. int n : determine hom many nodes would be reversed in the range of power of.
	@Returns: No return value
	@Descriptions: 
	Two integer values(begin, last) have a start order and an end order of the reverse range.
	Using while loop, reverse nodes for each range and update the range in manner of power(n,k).
	In this step, divide into 2 cases :
	1. If the range going to be reversed exceeds the entire list, just reverse for begin to end of the list.
	2. Otherwise, reverse for begin to last.
	Use reverse_range to reverse nodes for each range.
	@Error cases: No error case.
*/

void powerofN_reverse(struct linked_list* list, int n)
{
	//your code starts from here
	int last = 1;
	int begin = 1;
	int k = 0;
	while (list->number_of_nodes > begin) {
		if (last != 1 && begin != list->number_of_nodes) {
			if (list->number_of_nodes < last) {
				reverse_range(list, begin, list->number_of_nodes);
			}
			else {
				reverse_range(list, begin, last);
			}
		}
		k++;
		begin = last +1;
		last = last + (int)pow(n, k);
	}
}

/*
	@Function name: void print_list(struct linked_list* list)
	@Parameters: the list going to be printed
	@Returns:No return value
	@Descriptions: A temp pointer is initialized to point head of the list. Then, print the value of
	the temp pointer, moving the temp pointer using next pointer.
	@Error cases:
	1. If there is no list, then print error message.
 */
void print_list(struct linked_list* list)
{
	if (list_exist == 0)
	{
		printf("There is no list to print\n");
		return;
	}
	struct linked_node * temp = list->head;
	printf("****************************************************************************\n\n");
	printf("	Number of nodes: %d\n", list->number_of_nodes);
	printf("\n");
	int i = 0;
	for (i = 0; i < list->number_of_nodes; i++)
	{
		printf("%d   ", temp->value);
		temp = temp->next;
	}
	printf("\n");
	printf("****************************************************************************\n\n");
	free(temp);
}

