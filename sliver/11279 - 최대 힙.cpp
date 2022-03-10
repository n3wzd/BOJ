#include <iostream>
using namespace std;
int max_heap[100001];
int heap_size = 0;

bool Empty()
{
	return (heap_size == 0);
}

void Push(int n)
{
	max_heap[++heap_size] = n;
	int i = heap_size;

	for (; i > 1; i /= 2)
	{
		if (n <= max_heap[i / 2]) break;
		max_heap[i] = max_heap[i / 2];
	}
	max_heap[i] = n;
}

int Pop()
{
	if (Empty()) return 0;

	int res = max_heap[1];
	int last = max_heap[heap_size--];
	max_heap[1] = last;

	int i = 1;
	while (i <= heap_size / 2)
	{
		int m = (max_heap[i * 2] > max_heap[i * 2 + 1]) ? i * 2 : i * 2 + 1;
		if (last >= max_heap[m]) break;
		max_heap[i] = max_heap[m];
		i = m;
	}
	max_heap[i] = last;

	return res;
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