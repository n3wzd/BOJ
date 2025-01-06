#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <cmath>
using namespace std;

class Node {
public:
	int n;
	int dist;
	Node(int a, int b) { n = a, dist = b; }
};

set<int> cache[11];
int num, K, max_num = -1;

void BFS()
{
	queue<Node> q;
	q.push(Node(num, 0));
	cache[0].insert(num);

	while (!q.empty())
	{
		int v = q.front().n;
		int dist = q.front().dist;
		q.pop();

		if (dist == K)
		{
			max_num = max(max_num, v);
			continue;
		}

		string vs = to_string(v);
		int len = vs.size();
		for (int i = 0; i < len; i++)
		{
			for (int j = i + 1; j < len; j++)
			{
				string nvs = vs;
				nvs[i] = vs[j];
				nvs[j] = vs[i];
				if (nvs[0] == 48) continue;

				int next = stoi(nvs);
				if (cache[dist+1].find(next) == cache[dist+1].end())
				{
					q.push(Node(next, dist+1));
					cache[dist+1].insert(next);
				}
			}
		}
	}
}

int main()
{
	cin >> num >> K;
	BFS();
	cout << max_num << endl;
	return 0;
}