#include <iostream>
#include <cmath>
using namespace std;
int min_heap[100001];
int heap_size = 0;

bool Empty()
{
	return (heap_size == 0);
}

bool CMP(int a, int b) // a를 기준으로 절댓값이 작으면 true. 같을 경우, 크기가 작은 것이 true
{
	if (abs(a) != abs(b)) return abs(a) < abs(b);
	else return a <= b;
}

void Push(int n)
{
	min_heap[++heap_size] = n;
	int i = heap_size;

	for (; i > 1; i /= 2)
	{
		if (CMP(min_heap[i / 2], n)) break;
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
		int m = (CMP(min_heap[i * 2], min_heap[i * 2 + 1])) ? i * 2 : i * 2 + 1;
		if (CMP(last, min_heap[m])) break;
		min_heap[i] = min_heap[m];
		i = m;
	}
	min_heap[i] = last;

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