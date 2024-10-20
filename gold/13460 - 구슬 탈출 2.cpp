#include <iostream>
#include <queue>
using namespace std;
struct Point { int x, y; };
struct Game { Point red, blue; };
int N, M, score = -1, board[10][10], visited[10][10][10][10];
int dx[4] = { 1, 0, -1, 0 }, dy[4] = { 0, 1, 0, -1 };
queue<Game> q;

Point move(int x, int y, int d) {
    while (board[y + dy[d]][x + dx[d]] == 0)
        x += dx[d], y += dy[d];
    return { x, y };
}

void escape(int level) {
    int size = q.size();
    while (size--) {
        Game game = q.front(); q.pop();
        for (int d = 0; d < 4; d++) {
            Point red = game.red, blue = game.blue;

            board[blue.y][blue.x] = 1;
            red = move(red.x, red.y, d);
            bool redClear = board[red.y + dy[d]][red.x + dx[d]] == 2;

            if (!redClear)
                board[red.y][red.x] = 1;
            board[blue.y][blue.x] = 0;
            blue = move(blue.x, blue.y, d);
            bool blueClear = board[blue.y + dy[d]][blue.x + dx[d]] == 2;
            if (blueClear) {
                board[red.y][red.x] = 0;
                continue;
            }

            board[red.y][red.x] = 0; board[blue.y][blue.x] = 1;
            red = move(red.x, red.y, d);
            redClear = board[red.y + dy[d]][red.x + dx[d]] == 2;
            if (redClear) {
                score = level;
                return;
            }

            board[blue.y][blue.x] = 0;
            if (!visited[red.x][red.y][blue.x][blue.y]) {
                visited[red.x][red.y][blue.x][blue.y] = 1;
                q.push({ red, blue });
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    Game start;
    for (int y = 0; y < N; y++) {
        string str; cin >> str;
        for (int x = 0; x < M; x++) {
            if (str[x] == '#')
                board[y][x] = 1;
            if (str[x] == '.')
                board[y][x] = 0;
            if (str[x] == 'O')
                board[y][x] = 2;
            if (str[x] == 'R')
                start.red = { x, y };
            if (str[x] == 'B')
                start.blue = { x, y };
        }
    }
    q.push(start); visited[start.red.x][start.red.y][start.blue.x][start.blue.y] = 1;
    for (int level = 1; level <= 10 && score == -1; level++)
        escape(level);
    cout << score;
    return 0;
}
