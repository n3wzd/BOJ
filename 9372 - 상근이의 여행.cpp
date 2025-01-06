#include <iostream>
using namespace std;

int main()
{
	int T, N, M, a, b;
	cin >> T;
	while (T--)
	{
		scanf("%d%d", &N, &M);
		for (int i = 0; i < M; i++)
			scanf("%d%d", &a, &b);
		printf("%d\n", N-1);
	}
	return 0;
}