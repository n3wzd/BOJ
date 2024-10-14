#include <iostream>
#include <queue>
using namespace std;
struct Fireball { int x, y, mass, velo, dire; };
struct Board { int massSum = 0, veloSum = 0, cnt = 0; bool direOdd = 1, direEven = 1; };
int N, M, K, dx[8] = { 0, 1, 1, 1, 0, -1, -1, -1 }, dy[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
Board board[51][51];
queue<Fireball> q;

void magic() {
    int size = q.size();
    while (size--) {
        Fireball fire = q.front(); q.pop();
        int nx = (fire.x + (dx[fire.dire] + N) * fire.velo) % N, ny = (fire.y + (dy[fire.dire] + N) * fire.velo) % N;
        board[ny][nx].massSum += fire.mass;
        board[ny][nx].veloSum += fire.velo;
        board[ny][nx].cnt++;
        board[ny][nx].direOdd &= fire.dire % 2 == 1;
        board[ny][nx].direEven &= fire.dire % 2 == 0;
        fire.x = nx, fire.y = ny;
        q.push(fire);
    }

    size = q.size();
    while (size--) {
        Fireball fire = q.front(); q.pop();
        int x = fire.x, y = fire.y;
        if (board[y][x].cnt == 1)
            q.push(fire);
        else if (board[y][x].cnt > 1) {
            Board b = board[y][x];
            for (int d = 0; d < 4; d++)
                if (b.massSum / 5 > 0)
                    q.push({ x, y, b.massSum / 5, b.veloSum / b.cnt, d * 2 + (b.direOdd || b.direEven ? d * 0 : 1) });
        }
        board[y][x] = { 0, 0, 0, 1, 1 };
    }
}

int sumAll() {
    int sum = 0;
    while (!q.empty()) {
        sum += q.front().mass; q.pop();
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M >> K;
    for (int i = 0; i < M; i++) {
        int x, y, m, v, d;
        cin >> y >> x >> m >> v >> d;
        q.push({ x - 1, y - 1, m, v, d });
    }
    while (K--) magic();
    cout << sumAll();
    return 0;
}
