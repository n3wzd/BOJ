#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Node
{
public:
	int start, end;
};

bool cmp(Node a, Node b) {
	if (a.end != b.end) return a.end < b.end;
	else return a.start < b.start;
}

int main()
{
	int n;
	vector<Node> meeting;
	int result = 1, next;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		Node node;
		cin >> node.start >> node.end;
		meeting.push_back(node);
	}
	sort(meeting.begin(), meeting.end(), cmp);

	next = meeting[0].end;
	for (int i = 1; i < n; i++)
	{
		if (meeting[i].start >= next)
		{
			next = meeting[i].end;
			result++;
		}
	}

	cout << result << endl;
	return 0;
}