#include <iostream>
#include <vector>
using namespace std;
const int INF = 1e9;
struct Node { int v, c, d; };
int T, N, M, K, DP[101][10001];
vector<Node> graph[101];

int DFS(int n, int c) {
    if (DP[n][c] > 0)
        return DP[n][c];
    if (n == N)
        return 0;
    DP[n][c] = INF;
    for (Node next : graph[n])
        if(c + next.c <= M)
            DP[n][c] = min(DP[n][c], DFS(next.v, c + next.c) + next.d);
    return DP[n][c];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T >> N >> M >> K;
    while (K--) {
        int u, v, c, d;
        cin >> u >> v >> c >> d;
        graph[u].push_back({ v, c, d });
    }
    int answer = DFS(1, 0);
    if (answer == INF)
        cout << "Poor KCM";
    else
        cout << answer;
    return 0;
}
