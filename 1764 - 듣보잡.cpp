#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
set<string> list;
vector<string> unknown;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		string name1;
		cin >> name1;
		list.insert(name1);
	}
	for (int i = 0; i < M; i++)
	{
		string name2;
		cin >> name2;
		if (list.find(name2) != list.end())
			unknown.push_back(name2);
	}

	sort(unknown.begin(), unknown.end());
	int size = unknown.size();

	cout << size << "\n";
	for (int i = 0; i < size; i++)
		cout << unknown[i] << "\n";
	return 0;
}
