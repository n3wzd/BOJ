#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int list[500001];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> list[i];
	sort(list, list + N);

	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int key;
		cin >> key;
		cout << binary_search(list, list + N, key) << " ";
	}
	return 0;
}
