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

	Node(int n)
	{
		num = n;
	}
};

bool cmp(Node* a, Node* b) {
	return a->num < b->num;
}

int main()
{
	vector<Node*> arr;
	vector<Node*> seq;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a = i;
		if (i % 2 == 0) a *= -1;
		scanf("%d", &a);

		Node* node1 = new Node(a);
		Node* node2 = new Node(a);
		node1->other = node2;
		node2->other = node1;

		arr.push_back(node1);
		seq.push_back(node2);
	}
	sort(seq.begin(), seq.end(), cmp);

	int order = 0;
	seq[0]->order = order;
	for (int i = 1; i < n; i++)
	{
		if (seq[i]->num != seq[i - 1]->num) order++;
		seq[i]->order = order;
	}

	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]->other->order);

	return 0;
}