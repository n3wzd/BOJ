#include <iostream>
using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;

	for (; M <= 100; M++)
	{
		int d = N / M;
		int sum = (M % 2 == 0) ? (d + (d + 1)) * (M / 2) : d + (d * 2) * (M / 2);

		if (sum == N)
		{
			int start = d - ((M - 1) / 2);
			if (start < 0) break;

			for (int i = 0; i < M; i++)
				printf("%d ", start++);
			return 0;
		}
	}

	cout << -1 << endl;
	return 0;
}