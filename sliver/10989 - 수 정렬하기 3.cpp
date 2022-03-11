#include <iostream>
using namespace std;
# define NUM_MAX 10000

int n;
int cnt[10002] = { 0, };

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int num;
		scanf("%d", &num);
		cnt[num]++;
	}
	
	for (int i = 1; i <= NUM_MAX; i++)
		for (int c = 0; c < cnt[i]; c++)
			printf("%d\n", i);
	
	return 0;
}