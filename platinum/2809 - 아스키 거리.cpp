#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
const int TYPE = 26;
int Converter(char c) { return c - 'a'; }
int rangeField[300005];

class Node {
public:
	bool isEnd = 0;
	vector<Node*> child;
	Node* fail;
	int key, child_len = 0, ptn_len;

	Node(int k) {
		key = k, isEnd = 0, ptn_len = 0, child_len = 0;
		fail = nullptr;
	}

	~Node() {
		for (int i = 0; i < TYPE; i++)
			if (child[i])
				delete child[i];
	}

	int GetIdx(int k) {
		int i = 0;
		for (i = 0; i < child_len; i++)
			if (child[i]->key == k)
				return i;
		return child_len;
	}

	Node* GetChildByKey(int k) {
		int i = GetIdx(k);
		return (i < child_len) ? child[i] : nullptr;
	}

	void Insert(const char* str, int ptn) {
		if (!*str) {
			isEnd = 1;
			ptn_len = ptn;
			return;
		}

		int first = Converter(*str);
		int pos = GetIdx(first);
		if (pos == child_len) {
			child.push_back(new Node(first));
			child_len++;
		}
		child[pos]->Insert(str + 1, ptn);
	}
};
Node* root = new Node(0);

void Failure() {
	queue <Node*> q;
	q.push(root);
	root->fail = root;

	while (!q.empty()) {
		Node* v = q.front();
		q.pop();

		for (int i = 0; i < v->child_len; i++) {
			Node* next = v->child[i];
			if (next == nullptr)
				continue;

			if (v == root)
				next->fail = root;
			else {
				int nextKey = v->child[i]->key;
				Node* fNode = v->fail;

				while (fNode != root && fNode->GetChildByKey(nextKey) == nullptr)
					fNode = fNode->fail;
				Node* fNodeChild = fNode->GetChildByKey(nextKey);
				if (fNodeChild != nullptr)
					fNode = fNodeChild;
				next->fail = fNode;
			}
			if (next->fail->isEnd) {
				next->isEnd = 1;
				next->ptn_len = max(next->ptn_len, next->fail->ptn_len);
			}

			q.push(next);
		}
	}
}

int KMP(const char* T) {
	Node* v = root;
	int len = strlen(T);

	for (int w = 0; w < len; w++) {
		int c = Converter(T[w]);
		while (v != root && v->GetChildByKey(c) == nullptr)
			v = v->fail;
		Node* vChild = v->GetChildByKey(c);
		if (vChild != nullptr)
			v = vChild;

		if (v->isEnd) {
			rangeField[w - (v->ptn_len - 1)] += 1;
			rangeField[w + 1] -= 1;
		}
	}

	int sum = 0, layer = 0;
	for (int i = 0; i < len; i++) {
		layer += rangeField[i];
		if (layer > 0)
			sum++;
	}
	return len - sum;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, M;
	string street;
	cin >> N >> street >> M;

	for (int i = 0; i < M; i++) {
		string tile;
		cin >> tile;
		root->Insert(tile.c_str(), tile.size());
	}
	Failure();

	cout << KMP(street.c_str()) << "\n";
	return 0;
}
