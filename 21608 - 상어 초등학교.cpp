#include <iostream>
using namespace std;
struct Point { int x, y; };
int N, friends[402][4], board[21][21], scoreList[5] = { 0, 1, 10, 100, 1000 };
int dx[4] = { 1, 0, -1, 0 }, dy[4] = { 0, 1, 0, -1 };

int getFriends(int x, int y, int i) {
    int cnt = 0;
    for (int d = 0; d < 4; d++) {
        int nx = x + dx[d], ny = y + dy[d];
        if (nx >= 0 && nx < N && ny >= 0 && ny < N)
            for (int f = 0; f < 4; f++)
                if (board[ny][nx] == friends[i][f])
                    cnt++;
    }
    return cnt;
}

int getEmpty(int x, int y) {
    int cnt = 0;
    for (int d = 0; d < 4; d++) {
        int nx = x + dx[d], ny = y + dy[d];
        if (nx >= 0 && nx < N && ny >= 0 && ny < N && board[ny][nx] == 0)
            cnt++;
    }
    return cnt;
}

void seat(int i) {
    int seatX = 0, seatY = 0, curFriend = -1, curEmpty = -1;
    for (int y = N - 1; y >= 0; y--) {
        for (int x = N - 1; x >= 0; x--) {
            if (board[y][x] > 0)
                continue;
            int f = getFriends(x, y, i), e = getEmpty(x, y);
            if (f > curFriend) {
                curFriend = f, curEmpty = e;
                seatX = x, seatY = y;
            }
            else if (f == curFriend && e >= curEmpty) {
                curEmpty = e;
                seatX = x, seatY = y;
            }
        }
    }
    board[seatY][seatX] = i;
}

int getScore() {
    int score = 0;
    for (int y = 0; y < N; y++)
        for (int x = 0; x < N; x++)
            score += scoreList[getFriends(x, y, board[y][x])];
    return score;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N * N; i++) {
        int n; cin >> n;
        for (int f = 0; f < 4; f++)
            cin >> friends[n][f];
        seat(n);
    }
    cout << getScore();
    return 0;
}
