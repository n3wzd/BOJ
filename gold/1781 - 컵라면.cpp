#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
struct Ramen {
	int time, cup;
};
int N;
Ramen quest[200001];
priority_queue<int, vector<int>, greater<int>> pq;

bool cmp(Ramen a, Ramen b) {
	return (a.time != b.time) ? a.time < b.time : a.cup > b.cup;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) 
		cin >> quest[i].time >> quest[i].cup;
	sort(quest, quest + N, cmp);

	int pq_size = 1, reward = quest[0].cup;
	pq.push(quest[0].cup);
	for (int t = 1; t < N; t++) {
		if (pq_size < quest[t].time) {
			reward += quest[t].cup;
			pq.push(quest[t].cup);
			pq_size++;
		}
		else if (pq.top() < quest[t].cup) {
			reward += quest[t].cup - pq.top();
			pq.push(quest[t].cup);
			pq.pop();
		}
	}
	cout << reward;
	return 0;
}
