#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Node;

class Node {
public:
	int child_len = 0;
	string key;
	vector<Node*> child;
	Node(string key);
	~Node();
	void Insert(string* tunnel, int idx, int len);
	void Print(int depth);
};

bool cmp(Node* a, Node* b) {
	return a->key < b->key;
}

Node::Node(string key) {
	child_len = 0;
	this->key = key;
}

Node::~Node() {
	for (int i = 0; i < child_len; i++)
		if (child[i])
			delete child[i];
}

void Node::Insert(string* tunnel, int idx, int len) {
	if (idx == len) return;

	int pos = 0;
	for (pos = 0; pos < child_len; pos++)
		if (child[pos]->key == tunnel[idx])
			break;

	if (pos == child_len) {
		child.push_back(new Node(tunnel[idx]));
		child_len++;
	}

	child[pos]->Insert(tunnel, idx + 1, len);
}

void Node::Print(int depth) {
	for (int i = 0; i < depth; i++) cout << "--";
	if (depth >= 0) cout << key << "\n";

	sort(child.begin(), child.end(), cmp);
	for (int i = 0; i < child_len; i++)
		child[i]->Print(depth + 1);
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	Node* root = new Node("");

	cin >> N;
	for (int i = 0; i < N; i++) {
		int K;
		string tunnel[15];

		cin >> K;
		for (int k = 0; k < K; k++)
			cin >> tunnel[k];
		root->Insert(tunnel, 0, K);
	}
	root->Print(-1);
	return 0;
}