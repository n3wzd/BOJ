#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <memory.h>
#define SIZE 52
using namespace std;
int N;
vector<int> graph[SIZE];
int matching[SIZE];
bool visited[SIZE];

int block, evenLen = 0, oddLen = 0;
int num[SIZE], even[SIZE], odd[SIZE];
bool prime[3002] = { 0, };

bool DFS(int v) {
	if (odd[v] == block) return 0;
	for (int i = 0; i < graph[v].size(); i++) {
		int nv = graph[v][i];
		if (visited[nv] || (even[nv] == block)) continue;
		visited[nv] = 1;

		if (matching[nv] == 0 || DFS(matching[nv])) {
			matching[nv] = v;
			return 1;
		}
	}
	return 0;
}

int Bipartite() {
	int mat = 0;
	for (int v = 1; v <= N; v++) {
		memset(visited, 0, sizeof(visited));
		if (DFS(v)) mat++;
	}
	return mat;
}

void PrimeScanner(int n) {
	int sq = sqrt(n);
	for (int i = 2; i <= sq; i++) {
		int d = i * 2;
		while (d <= n) {
			prime[d] = 1;
			d += i;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> num[1];
	for (int i = 2; i <= N; i++) {
		cin >> num[i];
		if (num[i] % 2 == 0) even[++evenLen] = num[i];
		else odd[++oddLen] = num[i];
	}
	if ((num[1] % 2 == 0 && evenLen + 1 != oddLen) ||
		num[1] % 2 == 1 && evenLen != oddLen + 1) {
		cout << "-1";
		return 0;
	}

	PrimeScanner(3002);
	for (int i = 1; i <= oddLen; i++)
		for (int w = 1; w <= evenLen; w++)
			if(!prime[odd[i] + even[w]])
				graph[i].push_back(w);

	vector<int> ans;
	for (int i = 2; i <= N; i++) {
		if (prime[num[1] + num[i]]) continue;
		block = num[i];

		memset(matching, 0, sizeof(matching));
		int limit = (num[i] % 2 == 1) ? oddLen - 1 : oddLen;
		if (Bipartite() == limit)
			ans.push_back(num[i]);
	}

	sort(ans.begin(), ans.end());
	int len = ans.size();
	if (len == 0) cout << "-1";
	for (int i = 0; i < len; i++)
		cout << ans[i] << " ";
	return 0;
}
