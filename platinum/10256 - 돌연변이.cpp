#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
typedef long long ll;
const int TYPE = 4;
int Converter(char c) { 
	if (c == 'A') return 0;
	if (c == 'C') return 1;
	if (c == 'G') return 2;
	if (c == 'T') return 3;
	return 0;
}

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
Node* root;

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

ll KMP(const char* T) {
	Node* v = root;
	ll cnt = 0;
	int len = strlen(T);

	for (int w = 0; w < len; w++) {
		int i = Converter(T[w]);
		while (v != root && v->child[i] == nullptr)
			v = v->fail;
		if (v->child[i] != nullptr)
			v = v->child[i];

		if (v->isEnd)
			cnt++;
	}
	return cnt;
}

void AddTrie(string marker, int lo, int hi) {
	while (lo < hi) {
		swap(marker[lo], marker[hi]);
		lo++; hi--;
	}
	root->Insert(marker.c_str());
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int Q;
	cin >> Q;
	while (Q--) {
		int N, M;
		string DNA, marker;
		cin >> N >> M >> DNA >> marker;

		root = new Node();
		for (int i = 0; i < M; i++)
			for (int j = i + 1; j < M; j++)
				AddTrie(marker, i, j);
		root->Insert(marker.c_str());
		Failure();

		cout << KMP(DNA.c_str()) << "\n";
		delete root;
	}
	return 0;
}
