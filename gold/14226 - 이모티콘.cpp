#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
	int v, clip;
	Node(int a, int b) { v = a, clip = b; }
};

int S;
bool visited[1002][1002];
int dist[1002][1002];
queue<Node> q;

void Add(int v, int clip, int d) {
	if (v > 1001 || v < 0) return;
	if (!visited[v][clip]) {
		q.push(Node(v, clip));
		visited[v][clip] = 1;
		dist[v][clip] = d + 1;
	}
}

void BFS() {
	q.push(Node(1, 0));
	visited[1][0] = 1;

	while (!q.empty()) {
		Node n = q.front();
		int d = dist[n.v][n.clip];
		q.pop();

		if (n.v == S) {
			cout << d;
			return;
		}

		Add(n.v + n.clip, n.clip, d);
		Add(n.v, n.v, d);
		Add(n.v - 1, n.clip, d);
	}
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> S;
	BFS();
	return 0;
}
