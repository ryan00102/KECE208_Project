# HEAP createHeap()
1. HEAP h라는 포인터 변수에 메모리를 할당한다.
2. h의 ADT value 중에 integer value인 size는 0으로, integer array pointer인 heapData는 100의 사이즈를 갖도록 초기화한다.
3. HEAP h를 return 한다.

# void makeHeap(int arr[], int i, int size)
1. arr[i]의 left child는 arr의 2*i + 1번째 index, right child는 arr의2*i + 2번째 index로 선언한다.
2. arr[i]와 arr[i]의 left child, right child 중 가장 큰 값의 index를 largest라고 선언한다.
3. arr[i]가 가장 큰 값이 아니라면(largest != i), arr[i]와 arr[largest]의 값만 바꾸고, arr[largest]에 대하여 makeHeap 함수를 재귀적으로 호출한다.

# void buildHeap(HEAP h, int* array, int arraySize)
1. array에 들어있는 값들을 heap property를 갖추도록 makeHeap function을 array에 대해 실행한다.
2. heap property를 갖추게 된 array의 integer elements들을 h의 heapData 배열에 순서대로 대입한다.
3. 만약 heap(h)의 size가 0이거나, heap(h)가 Null이라면 에러 메시지를 출력한다.

# void deleteHeap(HEAP h)
1. 만약 heap(h)가 Null이라면 에러 메시지를 출력한다.
2. h의 heapData라는 array pointer를 free한 뒤, h를 free한다. 그리고 삭제 성공 메시지를 출력한다.

# int findDepth(HEAP h)
1. 만약 heap(h)가 Null이라면 에러 메시지를 출력한다.
2. HEAP h의 size에 베이스가 2인 로그 연산을 한 값에 내림 연산을 한 값을 integer value인 depth에 대입한다.
3. depth를 return한다.

# void insertNode(HEAP h, int value)
1. 만약 heap(h)가 Null이라면 에러 메시지를 출력한다.
2. 우선, HEAP h의 size를 1만큼 늘리고, 그 h의 heapData라는 array의 마지막 element에 value를 넣는다.
3. 그리고, 새로 값이 들어갔기 때문에, heap property가 무너졌을 수도 있으므로, heapData라는 array에 대해 makeHeap함수를 실행한다.

# int dequeueHeap(HEAP h)
1. 만약 heap(h)가 Null이라면 에러 메시지를 출력한다.
2. dequeue할 값인 heapData의 첫 element를 outnode에 넣는다.
3. heapData의 나머지 element들을 한 칸씩 앞으로 움직인 뒤, heap(h)의 size를 1만큼 줄인다.
4. 그리고, 값이 없어졌기 때문에, heap property가 무너졌을 수도 있으므로, heapData라는 array에 대해 makeHeap함수를 실행한다.
5. outnode를 return한다.

# void heapSort(HEAP h, int *heapsort, int count)
1. heapsort라는 array에 있는 값들을 heap property를 유지한 상태로 HEAP h에 넣는다.
2. heapData의 첫 element와 마지막 element를 swap한다.
3. Swap한 뒤에 마지막 element를 제외하고 나머지 array element들에 대해 makeHeap을 통해 heap property를 유지시킨다.
4. 새로운 첫 element와 원래 마지막 element를 제외한 나머지 element들 중 마지막 element를 swap하고 3을 반복한다.
5. 마지막으로 정렬된 리스트를 오름차순으로 출력한다.

# void swap(int*n1, int*n2)
1. integer value인 temp를 이용하여 두 개의 integer pointer value를 바꿔준다.

# void printHeap(HEAP h)
1. heapData의 size와 findDepth함수를 통해 구한 h의 depth(level)을 이용하여 heapData라는 array의 element들을 binary complete tree 모양으로 출력한다.
2. 그리고 heap의 depth와 size도 출력한다.