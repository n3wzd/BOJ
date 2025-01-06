#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Node
{
public:
	int x = 0, y = 0;
};

bool cmp(Node a, Node b) {
	return a.x < b.x;
}

int n;
vector<Node> list;
int cache[1002] = { 0, };

int DP(int i) // LIS
{
	if (cache[i] != 0) return cache[i];

	cache[i] = 1;
	for (int w = i + 1; w <= n; w++)
	{
		if (list[w].y > list[i].y)
		{
			int a = cache[i];
			int b = 1 + DP(w);
			if (b > a)
				cache[i] = b;
		}
	}
	return cache[i];
}

int main()
{
	cin >> n;

	Node temp;
	list.push_back(temp);
	for (int i = 1; i <= n; i++)
	{
		Node node;
		cin >> node.x >> node.y;
		list.push_back(node);
	}
	sort(list.begin(), list.end(), cmp);

	cout << n - (DP(0) - 1) << endl;
	return 0;
}