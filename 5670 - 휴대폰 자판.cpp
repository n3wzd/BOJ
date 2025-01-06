#include <iostream>
#include <cmath>
using namespace std;
const int TYPE = 26;
int N;
string dict[100001];

int Converter(char c) {
	return c - 'a';
}

class Node {
public:
	bool isRoot = 0;
	bool isEnd = 0;
	int child_cnt = 0;
	Node* child[TYPE];

	Node() {
		isRoot = 0;
		isEnd = false;
		child_cnt = 0;
		for (int i = 0; i < TYPE; i++)
			child[i] = nullptr;
	}

	~Node() {
		for (int i = 0; i < TYPE; i++)
			if (child[i])
				delete child[i];
	}

	void Insert(const char* str) {
		if (!*str) {
			isEnd = true;
			return;
		}

		int first = Converter(*str);
		if (child[first] == nullptr) {
			child[first] = new Node();
			child_cnt++;
		}
		child[first]->Insert(str + 1);
	}

	int Find(const char* str) {
		if (!*str)
			return 0;

		int input = child[Converter(*str)]->Find(str + 1);
		if((isEnd && child_cnt >= 1) || child_cnt >= 2 || isRoot) input++;
		return input;
	}
};

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	while (cin >> N){
		Node* root = new Node();
		root->isRoot = 1;

		for (int i = 0; i < N; i++) {
			cin >> dict[i];
			root->Insert(dict[i].c_str());
		}

		int sum = 0;
		for (int i = 0; i < N; i++)
			sum += root->Find(dict[i].c_str());

		cout << fixed; cout.precision(2);
		cout << round((double)sum / N * 100) / 100 << "\n";
		delete root;
	}
	return 0;
}