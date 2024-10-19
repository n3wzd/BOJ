#include <iostream>
using namespace std;
int N, M, diceX, diceY, K, Dc = 0, Dl = 3, Du = 1;
int board[21][21], dx[4] = { 1, -1, 0, 0 }, dy[4] = { 0, 0, -1, 1 };
int mark[6], sym[6] = { 5, 4, 3, 2, 1, 0 };

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M >> diceY >> diceX >> K;
    for (int y = 0; y < N; y++)
        for (int x = 0; x < M; x++)
            cin >> board[y][x];
    while (K--) {
        int d;
        cin >> d;
        int nx = diceX + dx[d - 1], ny = diceY + dy[d - 1];
        if (nx < 0 || nx >= M || ny < 0 || ny >= N)
            continue;
        diceX = nx, diceY = ny;
        if (d == 1) {
            int tmp = sym[Dc];
            Dc = Dl; Dl = tmp;
        }
        if (d == 2) {
            int tmp = sym[Dl];
            Dl = Dc; Dc = tmp;
        }
        if (d == 3) {
            int tmp = sym[Du];
            Du = Dc; Dc = tmp;
        }
        if (d == 4) {
            int tmp = sym[Dc];
            Dc = Du; Du = tmp;
        }
        if (board[diceY][diceX] == 0)
            board[diceY][diceX] = mark[sym[Dc]];
        else {
            mark[sym[Dc]] = board[diceY][diceX];
            board[diceY][diceX] = 0;
        }
        cout << mark[Dc] << "\n";
    }
    return 0;
}
