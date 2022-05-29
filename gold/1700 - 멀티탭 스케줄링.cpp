#include <iostream>
#include <queue>
using namespace std;
int N, K, cache_size = 0, fault = 0;
int ready[101];
int cache[101];
queue<int> next_pos[101];

int OPT(int i) {
	int max_dist = -1, target = -1;
	for (int c = 0; c < cache_size; c++) {
		int dist = 999;
		if (!next_pos[cache[c]].empty())
			dist = next_pos[cache[c]].front() - i;

		if (dist > max_dist) {
			max_dist = dist;
			target = c;
		}
	}
	return target;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;
	for (int i = 0; i < K; i++) {
		cin >> ready[i];
		next_pos[ready[i]].push(i);
	}
		
	for (int i = 0; i < K; i++) {
		next_pos[ready[i]].pop();
		bool isFault = 1;
		for (int c = 0; c < cache_size; c++)
			if (cache[c] == ready[i])
				isFault = 0;

		if(isFault) {
			if (cache_size < N) cache[cache_size++] = ready[i];
			else {
				cache[OPT(i)] = ready[i];
				fault++;
			}
		}
	}
	cout << fault;
	return 0;
}
