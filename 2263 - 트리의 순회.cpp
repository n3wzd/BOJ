#include <iostream>
using namespace std;

int N;
int post[100002];
int in[100002];

void Order(int root, int end, int diff)
{
	if (root - end < 0) return;

	printf("%d ", post[root]);
	if (root - end == 0) return;

	int mid = in[post[root]] - diff;
	Order(mid - 1, end, diff); // left
	Order(root - 1, mid, diff + 1); // right
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int num;
		scanf("%d", &num);
		in[num] = i;
	}
	for (int i = 0; i < N; i++) scanf("%d", &post[i]);
	Order(N - 1, 0, 0);
	return 0;
}