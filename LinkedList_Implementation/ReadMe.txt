# struct linked_list* create_list(int number_of_nodes, int list_type)
1-1. input value인 number_of_nodes가 1보다 작으면 에러 메시지를 출력한다.
1-2. 전역 변수 list_exist가 1이라면 이미 리스트가 존재한다는 뜻이기 때문에, 에러 메시지를 출력한다.
1-3. input value인 list_type이 0 또는 1이 아니라면, list의 type을 정할 수 없기 때문에, 에러 메시지를 출력한다.
2. new_list라는 포인터 변수에 메모리를 할당하고 new_list의 ADT value들을 초기화한다.
3. new_list에 list_type value에 따라서 1부터 number_of_nodes까지의 정수 값을 가진 노드들을 number_of_nodes만큼 random한 순서로 insert 하거나 push한다. 이 때 list에 같은 값이 등장하지 않도록, bFound value를 활용한다.
4. list의 노드들을 다 insert하거나 push했다면, 전역변수 list_exist를 1로 reset하고, new_list를 return한다.

# struct linked_node* create_node(int node_value)
1. 새로운 노드를 위한 주소를 할당한다.
2. 노드의 ADT value들을 초기화 한 뒤, 그 노드를 return한다.

# void insert_node(struct linked_list* list, struct linked_node* node)
1. node의 next, prev pointer를 NULL로 초기화해둔다.
2. 경우를 나눠 insert한다
 1) list가 비어있는 경우, insert하는 노드를 list의 head와 tail에 연결한다.
 2) list가 노드 하나만 가지고 있는 경우, insert 하는 노드를 그 노드와 연결하고 list의 head는 insert하는 노드를 가리킨다. list의 tail은 기존의 노드를 가리킨다.
 3) list가 2개 이상의 노드를 가지고 있는 경우, insert하는 노드는 기존의 head가 가리키고 있던 노드와 연결되고, list의 head는 insert하는 노드를 가리킨다.
3. list의 ADT value인 number_of_nodes를 1 증가시키고 type_of_list를 0으로 reset한다.

# void remove_list(struct linked_list* list)
1. 삭제할 노드를 담아둘 deletenode를 하나 만들어둔다.
2. list의 head부터 삭제하기 때문에 deletenode에 list의 head주소를 담아둔다.
3-1. list의 number_of_nodes가 1이 되기 전까지는 list의 head를 next 주소를 이용하여 움직이면서 삭제한다.
3-2. list의 number_of_nodes가 1이 되면 더 이상 list의 head를 움직일 필요가 없기 때문에 free(deletenode)만 한다.
4. list의 노드가 다 삭제되면, 전체 리스트도 free(list)를 통해 아예 제거해준다. 그리고 list_exist의 값을 0으로 reset한다.

# void remove_node(struct linked_list* list, int rm_node_value)
1. list의 종류가 Stack이면 에러 메시지를 출력한다.
2. list에 rm_node_value를 가진 노드가 없으면(삭제할 노드가 없으면) 에러 메시지를 출력한다.
3. 삭제할 정수 값을 가진 노드의 주소를 rm_node에 저장한다.
4-1. 만약 현재 리스트의 노드 개수가 1이면 remove_list를 실행하여 리스트를 아예 제거한다. list의 number_of_nodes를 1감소시킨다.
4-2. rm_node가 list의 head라면 list의 새로운 head를 지정하고 free(rm_node)로 삭제한다. list의 number_of_nodes를 1감소시킨다.
4-3. rm_node가 list의 tail이라면 list의 새로운 tail을 지정하고 free(rm_ndoe)로 삭제한다. list의 number_of_nodes를 1감소시킨다.
4-4. rm_node가 list의 tail도 head도 아니라면 rm_node의 previos노드와 next노드를 연결해주고 free(rm_node)로 삭제한다. list의 number_of_nodes를 1감소시킨다.

# void delete_range(struct linked_list* list, int id_1, int id_2)
1. temp pointer를 이용하여 check_1(id_1을 가진 노드가 있는지), check_2(id_2을 가진 노드가 있는지), position_1(id_1을 가진 노드의 위치), position_2(id_2을 가진 노드의 위치)의 값을 넣는다.
2. 그리고 id_1을 가진 노드의 주소를 start_node 포인터 변수에 대입한다.
3-1. check_1과 check_2가 모두 1이 아니면 (list에 id_1과 id_2를 integer value로 가진 노드가 두개 다 있지 않으면), 에러 메시지를 출력한다.
3-2. position_1이 position_2보다 크다면(id_1을 가진 node가 id_2를 가진 node 보다 뒤에 있다면), 에러 메시지를 출력한다.
4. id_1과 id_2 사이의 노드들의 개수만큼의 사이즈를 가진 배열을 동적할당하고, 그 배열에 id_1과 id_2사이의 노드들의 integer value들 값을 넣는다. 그리고 기존의 remove_node함수를 이용하여 그 배열에 있는 모든 integer value값들에 대한 삭제를 진행한다.

2. 
# void push_Stack(struct linked_list* list, struct linked_node* node)
1. list의 종류가 normal이면 에러 메시지를 출력한다.
2. list가 비어있으면 새로운 노드를 list의 head와 tail에 모두 연결한다. list의 number_of_nodes를 1증가시킨다.
3. 그렇지 않으면, list의 tail이 새로운 노드를 가리킨다. list의 number_of_nodes를 1증가시킨다.

# void pop_Stack(struct linked_list* list, int number)
1. 삭제할 노드를 담아둘 deletenode를 하나 만들어둔다.
2. list의 종류가 stack이 아닌 경우, 삭제하는 node의 개수가 1보다 작은 경우, 삭제하는 node의 개수가 현재 list에 있는 노드의 개수보다 큰 경우, 에러 메시지를 출력한다.
2-1. list에 있는 노드의 개수가 삭제하는 노드의 개수와 같으면 remove_list(list)로 리스트를 아예 삭제한다.
3-1. 현재 list의 노드 개수가 1이면 deletenode에 list의 tail의 주소를 담고 삭제한 뒤, 리스트를 삭제한다. list의 number_of_nodes를 1감소시킨다.
3-2. 현재 list의 노드 개수가 1보다 크고, 삭제한 뒤에도 노드가 남아있을 것이라면, deletenode에 list의 tail의 주소를 담고 포인터를 이용하여 deletenode를 list로부터 분리시킨 뒤 deletenode만 삭제한다. list의 number_of_nodes를 1감소시킨다.

# void search_node(struct linked_list* list, int find_node_value)
1. list 안에서 traverse를 하기 위한 노드 temp를 만들어둔다. 
2. temp가 NULL에 도달할 때까지 find_node_value를 가진 node를 찾고, 찾으면 node_exist를 1로 reset하고 몇번째 노드에 있는지 출력한 뒤 반복문을 break한다.
3. node_exist가 1이 아니면(find_node_value를 가진 node가 없다면) 에러메시지를 출력한다.

# void swap_nodes(struct linked_list* list, int node1, int node2)
1. list의 number_of_nodes가 2보다 작을 경우 에러 메시지를 출력한다.
2. temp 포인터를 이용하여 node1을 value로 갖고 있는 노드(first)와 node2를 value로 갖고 있는 노드(second)를 찾는다. 처음에, first와 second는 NULL로 초기화 되어있다.
3-1. first와 second 중 둘 중 하나가 NULL이거나 둘 다 NULL이면(list에 node1을 value로 가진 노드와 node2를 value로 가진 노드 중 둘 다 없거나 둘 중 하나가 없다면), 에러메시지를 출력한다.
3-2. node1과 node2의 값이 같다면, swap할 것이 없기 때문에, 에러 메시지를 출력한다.
4. 정상적으로 first와 second에 노드들의 주소가 각각 담겼다면 case를 나눈다.
 1) first(node1)가 list의 head이고, second(node2)가 list의 tail이 아닌 경우,
 2) second(node2)가 list의 head이고, first(node1)이 list의 tail이 아닌 경우,
 3) first(node1)가 list의 head가 아니고, second(node2)가 list의 tail인 경우,
 4) second(node2)가 list의 head가 아니고, first(node1)가 list의 tail인 경우,
 5) first(node1)가 list의 head이고, second(node2)가 list의 tail인 경우,
 6) second(node2)가 list의 head이고, first(node1)가 list의 tail인 경우,
 7) first(node1), second(node2)가 모두 list의 head나 tail이 아닌 경우,
그리고 각각의 case에 대해서 node1을 value로 갖고 있는 노드와 node2를 value로 갖고 있는 노드가 서로 인접해있는지에 따라서도 case를 분류한다. 각각의 case마다 포인터를 적절히 바꿔준다.

# void forward_by_one(struct linked_list* list)
1. list의 노드 개수가 2보다 작으면 rotate할 노드가 없기 때문에 에러 메시지를 출력한다.
2-1. list가 Stack이라면 에러 메시지를 출력한다.
2-2. list의 전체 노드의 위치를 움직이는 것이 아니라 tail과 head pointer만을 움직인다 :  list의 tail에 list의 head가 가리키는 주소를 할당하고 list의 head는 head의 다음 노드의 주소를 할당한다.

# void backward_by_one(struct linked_list* list)
1. list의 노드 개수가 2보다 작으면 rotate할 노드가 없기 때문에 에러 메시지를 출력한다.
2-1. list가 Stack이라면 에러 메시지를 출력한다.
2-2. list의 전체 노드의 위치를 움직이는 것이 아니라 tail과 head pointer만을 움직인다 :  list의 head에 list의 tail이 가리키는 주소를 할당하고 list의 tail은 tail의 이전 노드의 주소를 할당한다.

# void reverse_range(struct linked_list* list, int order1, int order2)
1-1. order1이 order2보다 크다면 순서가 잘못되었으므로 에러 메시지를 출력한다.
1-2. order2가 list의 node의 전체 개수보다 크다면, 에러 메시지를 출력한다.
1-3. order1이 0이하라면, 에러 메시지를 출력한다.
2. order1부터 order2까지의 node들의 integer value를 담을 배열을 만든다.
3. next 포인터를 이용하여 order1에 위치한 노드의 주소를 firstnode에 저장한다.
4. 만들어뒀던 비어있는 배열에 order1부터 order2까지의 integer value를 모두 저장한다.
5. swap_nodes 함수를 이용하여 order1부터 order2까지의 범위에서, 양 끝에 있는 노드들을 swap하고, 그 다음 양끝에 있는 노드들을 swap하고 계속 진행하면서 swap되는 노드들이 가운데에서 만날 때까지 swap하면 순서가 온전히 뒤바뀌게 된다.

# void powerofN_reverse(struct linked_list* list, int n)
1. begin과 last라는 integer 변수에 reverse를 할 범위의 시작 부분과 끝 부분을 저장한다.
2-1. 반복문을 통해 [begin, last]에 대한 reverse가 끝나면 begin = last + 1, last = last + pow(n,k)를 해줌으로써 그 다음 범위를 설정한다. 
2-2. 이 때, last가 list의 노드의 전체 개수보다 크다면(reverse가 일어나는 범위가 list의 전체 노드를 초과한다면), [begin, list->number_of_nodes]의 범위에 대한 reverse만 진행한다.
2-3, 추가적으로, reverse하는 범위의 크기가 1이라면 reverse를 진행하지 않는다.
3. reverse를 진행할 때 기존의 reverse_range 함수를 이용한다.
 
# void print_list(struct linked_list* list)
1. list의 list_exist가 0이라면(리스트가 존재하지 않는다면), 에러 메시지를 출력한다.
2. temp pointer가 list의 head를 가리키도록 초기화하고, list의 head의 value부터 출력하고 next pointer를 이용하여 이후의 노드들에 접근하여 그 노드들의 value를 print한다.

