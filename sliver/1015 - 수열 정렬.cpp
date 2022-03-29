#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Node
{
public:
	int num;
	int order;
	Node* other;
	Node(int n) { num = n; }
};

bool cmp(Node* a, Node* b) {
	return a->num < b->num;
}

Node* arr[52];
Node* seq[52];

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a;
		scanf("%d", &a);

		Node* node1 = new Node(a);
		Node* node2 = new Node(a);
		node1->other = node2;
		node2->other = node1;

		arr[i] = node1;
		seq[i] = node2;
	}
	stable_sort(seq, seq + n, cmp);

	for (int i = 0; i < n; i++)
		seq[i]->order = i;

	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]->other->order);

	return 0;
}