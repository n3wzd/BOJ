#include <iostream>
#include <set>
using namespace std;

int N, M, num, cnt = 0;
set<int> imset;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		imset.insert(num);
	}
	for (int i = 0; i < M; i++)
	{
		cin >> num;
		if (imset.find(num) != imset.end()) cnt++;
	}
	cout << N + M - (cnt * 2);
	return 0;
}