#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
const int TYPE = 26;
int Converter(char c) { return c - 'a'; }

class Node {
public:
	bool isEnd = 0;
	Node* child[TYPE];
	Node* fail;

	Node() {
		isEnd = 0;
		for (int i = 0; i < TYPE; i++)
			child[i] = nullptr;
		fail = nullptr;
	}

	~Node() {
		for (int i = 0; i < TYPE; i++)
			if (child[i])
				delete child[i];
	}

	void Insert(const char* str) {
		if (!*str) {
			isEnd = 1;
			return;
		}

		int first = Converter(*str);
		if (child[first] == nullptr)
			child[first] = new Node();
		child[first]->Insert(str + 1);
	}
};
Node* root = new Node();

void Failure() {
	queue <Node*> q;
	q.push(root);
	root->fail = root;

	while (!q.empty()) {
		Node* v = q.front();
		q.pop();

		for (int i = 0; i < TYPE; i++) {
			Node* next = v->child[i];
			if (next == nullptr)
				continue;

			if (v == root)
				next->fail = root;
			else {
				Node* fNode = v->fail;
				while (fNode != root && fNode->child[i] == nullptr)
					fNode = fNode->fail;
				if (fNode->child[i] != nullptr)
					fNode = fNode->child[i];
				next->fail = fNode;
			}
			if (next->fail->isEnd)
				next->isEnd = 1;

			q.push(next);
		}
	}
}

bool KMP(const char* T) {
	Node* v = root;
	bool ok = 0;
	int len = strlen(T);

	for (int w = 0; w < len; w++) {
		int i = Converter(T[w]);
		while (v != root && v->child[i] == nullptr)
			v = v->fail;
		if (v->child[i] != nullptr)
			v = v->child[i];

		if (v->isEnd)
			ok = 1;
	}
	return ok;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	cin >> N;
	while (N--) {
		string s;
		cin >> s;
		root->Insert(s.c_str());
	}
	Failure();

	cin >> N;
	while (N--) {
		string s;
		cin >> s;
		cout << (KMP(s.c_str()) ? "YES" : "NO") << "\n";
	}
	return 0;
}
