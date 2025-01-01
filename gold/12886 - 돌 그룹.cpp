#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
vector<int> A(3);
bool visited[1501][1501];
queue<vector<int>> q;

void add(vector<int> B) {
    sort(B.begin(), B.end());
    if (!visited[B[0]][B[2]]) {
        q.push(B);
        visited[B[0]][B[2]] = 1;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> A[0] >> A[1] >> A[2]; sort(A.begin(), A.end());
    q.push({ A[0], A[1], A[2] }); visited[A[0]][A[2]] = 1;
    while(!q.empty()) {
        auto B = q.front(); q.pop();
        if (B[0] == B[2]) {
            cout << 1;
            return 0;
        }
        if (B[0] != B[1])
            add({ B[0] + B[0], B[1] - B[0], B[2] });
        if (B[1] != B[2])
            add({ B[0], B[1] + B[1], B[2] - B[1] });
        if (B[0] != B[2])
            add({ B[0] + B[0], B[1], B[2] - B[0] });
    }
    cout << 0;
    return 0;
}
