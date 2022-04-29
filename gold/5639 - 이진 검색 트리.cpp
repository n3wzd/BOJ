#include <iostream>
using namespace std;

class Node {
public:
	int key;
	Node* left;
	Node* right;
	Node(int d) { key = d, left = nullptr, right = nullptr; }
};

int N = 0;
int tree[10002];
Node* root;

void Insert(Node* pos, int data)
{
	if (data < pos->key)
	{
		if (pos->left == nullptr) pos->left = new Node(data);
		else Insert(pos->left, data);
	}
	else
	{
		if (pos->right == nullptr) pos->right = new Node(data);
		else Insert(pos->right, data);
	}
}

void Postorder(Node* v)
{
	if (v == nullptr) return;
	Postorder(v->left);
	Postorder(v->right);
	cout << v->key << "\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int num;
	while (cin >> num) tree[N++] = num;

	root = new Node(tree[0]);
	for (int i = 1; i < N; i++)
		Insert(root, tree[i]);
	Postorder(root);
	return 0;
}