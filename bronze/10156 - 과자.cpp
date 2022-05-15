#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, K, M;
	cin >> N >> K >> M;
	cout << max(0, N * K - M);
	return 0;
}
