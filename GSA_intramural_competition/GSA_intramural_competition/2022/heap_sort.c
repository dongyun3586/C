#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200

typedef struct {
	int key;
} element;

typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size;
} HeapType;

HeapType* create()
{
	HeapType* h = (HeapType*)malloc(sizeof(HeapType));
	h->heap_size = 0;
	return h;
}

// 현재 요소의 개수가 heap_size인 히프 h에 item을 삽입한다.
void insert_min_heap(HeapType* h, element item)
{
	int i = ++(h->heap_size);

	//  트리를 거슬러 올라가면서 부모 노드와 비교하는 과정
	while ((i != 1) && (item.key < h->heap[i / 2].key)) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item;     // 새로운 노드를 삽입
}

element delete_min_heap(HeapType* h)
{
	int parent, child;
	element item, temp;

	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;

	while (child <= h->heap_size) {
		// 현재 노드의 자식노드 중 더 작은 자식노드를 찾는다.
		if ((child < h->heap_size) && (h->heap[child].key) > h->heap[child + 1].key)
			child++;
		if (temp.key <= h->heap[child].key) break;
		// 한 단계 아래로 이동
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;

	return item;
}

void printHeap(HeapType* h) {
	printf("\n히프 트리: ");
	for (int i = 1; i <= h->heap_size; i++) {
		printf("%d ", h->heap[i]);
	}
}

void heap_sort(element arr[], int n) {
	HeapType* heap = create();

	for (int i = 0; i < n; i++)
		insert_min_heap(heap, arr[i]);

	for (int i = 0; i < n; i++)
		arr[i] = delete_min_heap(heap);

	free(heap);
}

int main(void)
{
	element arr[] = { 23, 56, 11, 9, 56, 99, 27, 34 };
	int arr_size = sizeof(arr) / sizeof(element);

	heap_sort(arr, arr_size);

	for (int i = 0; i < arr_size; i++)
		printf("%d ", arr[i].key);
	printf("\n");

	return 0;
}