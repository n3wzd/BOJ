#include <iostream>
using namespace std;
int min_heap[100001];
int heap_size = 0;

bool Empty()
{
	return (heap_size == 0);
}

void Push(int n)
{
	min_heap[++heap_size] = n;
	int i = heap_size;

	for (; i > 1; i /= 2)
	{
		if (n >= min_heap[i / 2]) break;
		min_heap[i] = min_heap[i / 2];
	}
	min_heap[i] = n;
}

int Pop()
{
	if (Empty()) return 0;

	int res = min_heap[1];
	int last = min_heap[heap_size--];
	min_heap[1] = last;

	int i = 1;
	while (i <= heap_size / 2)
	{
		int m = (min_heap[i * 2] < min_heap[i * 2 + 1]) ? i * 2 : i * 2 + 1;
		if (last <= min_heap[m]) break;
		min_heap[i] = min_heap[m];
		i = m;
	}
	min_heap[i] = last;

	return res;
}

void Print()
{
	for (int i = 1; i <= heap_size; i++)
		printf("%d ", min_heap[i]);
	printf("\n");
}

int main()
{
	int t;
	scanf("%d", &t);

	for (; t > 0; t--)
	{
		int cmd;
		scanf("%d", &cmd);
		if (cmd == 0) printf("%d\n", Pop());
		else Push(cmd);
	}

	return 0;
}