#include <iostream>
using namespace std;
const int TYPE = 10;
bool consistency = 1;
string phone[10001];

int Converter(char c) {
	return c - '0';
}

class Node {
public:
	bool isEnd = 0;
	Node* child[TYPE];

	Node() {
		isEnd = false;
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
		if (child[first] == nullptr)
			child[first] = new Node();
		child[first]->Insert(str + 1);
	}

	bool Find(const char* str) {
		if (!*str) {
			if (isEnd) return true;
			return false;
		}
		else if (isEnd) consistency = 0;

		int first = Converter(*str);
		if (child[first] == nullptr)
			return false;
		return child[first]->Find(str + 1);
	}
};

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T, N;
	cin >> T;
	while (T--) {
		consistency = 1;
		Node* root = new Node();

		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> phone[i];
			root->Insert(phone[i].c_str());
		}
		for (int i = 0; i < N; i++)
			root->Find(phone[i].c_str());

		if (consistency) cout << "YES" << "\n";
		else cout << "NO" << "\n";
		delete root;
	}
	return 0;
}
