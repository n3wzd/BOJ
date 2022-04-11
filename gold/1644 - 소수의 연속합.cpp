#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int N, cnt = 0;
bool prime[4000002] = { 0, };
long long sum = 0;
vector<int> arr;

int main()
{
	cin >> N;

	int sq = sqrt(N);
	for (int i = 2; i <= sq; i++)
	{
		int d = i * 2;
		while (d <= N)
		{
			prime[d] = 1;
			d += i;
		}
	}
	for (int i = 2; i <= N; i++)
	{
		if (!prime[i])
		{
			arr.push_back(i);
			sum += i;
		}
	}
	
	int size = arr.size();
	int start = 0, end = size - 1;
	while (end < size && start <= end)
	{
		if (sum > N) sum -= arr[end--];
		else if (sum <= N)
		{
			if (sum == N) cnt++;
			if (end == size - 1) break;
			sum -= arr[start++];
			sum += arr[++end];
		}
	}

	cout << cnt << endl;
	return 0;
}