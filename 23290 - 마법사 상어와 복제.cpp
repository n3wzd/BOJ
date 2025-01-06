#include <iostream>
using namespace std;
struct Point { int x, y; };
struct Board { int fish[8], copiedFish[8], movedFish[8]; int markTime = -9; };
int M, S, gameTime;
int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 }, dy[8] = { 0 , -1, -1, -1, 0, 1, 1, 1 };
int indexToDire[4] = { 2, 0, 6, 4 };
Board board[4][4]; Point sharkPos;

void startCopyMagic(int x, int y) {
    for (int d = 0; d < 8; d++)
        board[y][x].copiedFish[d] = board[y][x].fish[d];
}

void activeCopyMagic(int x, int y) {
    for (int d = 0; d < 8; d++)
        board[y][x].fish[d] += board[y][x].copiedFish[d];
}

void moveFish(int x, int y) {
    for (int fish = 0; fish < 8; fish++) {
        for (int dd = 0; dd < 8; dd++) {
            int newFish = (fish - dd + 8) % 8;
            int nx = x + dx[newFish], ny = y + dy[newFish];
            if (nx < 0 || nx >= 4 || ny < 0 || ny >= 4 || (nx == sharkPos.x && ny == sharkPos.y) || gameTime <= board[ny][nx].markTime + 2)
                continue;
            board[ny][nx].movedFish[newFish] += board[y][x].fish[fish];
            board[y][x].fish[fish] = 0;
            break;
        }
    }
}

void moveUpdateFish(int x, int y) {
    for (int d = 0; d < 8; d++) {
        board[y][x].fish[d] += board[y][x].movedFish[d];
        board[y][x].movedFish[d] = 0;
    }
}

int getAllFish(int x, int y) {
    int cnt = 0;
    for (int d = 0; d < 8; d++)
        cnt += board[y][x].fish[d];
    return cnt;
}

int getFishCnt(int x, int y, int dire[]) {
    Point visited[3];
    int cnt = 0;
    for (int dist = 0; dist < 3; dist++) {
        x += dx[dire[dist]], y += dy[dire[dist]];
        if (x < 0 || x >= 4 || y < 0 || y >= 4)
            return -1;
        bool isVisited = 0;
        for (int i = 0; i < dist; i++)
            isVisited |= (visited[i].x == x && visited[i].y == y);
        if (!isVisited)
            cnt += getAllFish(x, y);
        visited[dist] = { x, y };
    }
    return cnt;
}

void sharkMove() {
    int maxCnt = 0, maxDire = 0;
    for (int d = 63; d >= 0; d--) {
        int dire[3] = { indexToDire[d / 16], indexToDire[(d / 4) % 4], indexToDire[d % 4] };
        int cnt = getFishCnt(sharkPos.x, sharkPos.y, dire);
        if (cnt >= maxCnt) {
            maxCnt = cnt;
            maxDire = d;
        }
    }
    int dire[3] = { indexToDire[maxDire / 16], indexToDire[(maxDire / 4) % 4], indexToDire[maxDire % 4] };
    for (int dist = 0; dist < 3; dist++) {
        sharkPos.x += dx[dire[dist]], sharkPos.y += dy[dire[dist]];
        if (getAllFish(sharkPos.x, sharkPos.y) > 0) {
            board[sharkPos.y][sharkPos.x].markTime = gameTime;
            for (int d = 0; d < 8; d++)
                board[sharkPos.y][sharkPos.x].fish[d] = 0;
        }
    }
}

int sumAll() {
    int sum = 0;
    for (int y = 0; y < 4; y++)
        for (int x = 0; x < 4; x++)
            sum += getAllFish(x, y);
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> M >> S;
    while (M--) {
        int fx, fy, fd; cin >> fy >> fx >> fd;
        board[fy - 1][fx - 1].fish[fd - 1]++;
    }
    cin >> sharkPos.y >> sharkPos.x; sharkPos.y--, sharkPos.x--;
    while (S--) {
        for (int y = 0; y < 4; y++)
            for (int x = 0; x < 4; x++)
                startCopyMagic(x, y);
        for (int y = 0; y < 4; y++)
            for (int x = 0; x < 4; x++)
                moveFish(x, y);
        for (int y = 0; y < 4; y++)
            for (int x = 0; x < 4; x++)
                moveUpdateFish(x, y);
        sharkMove();
        for (int y = 0; y < 4; y++)
            for (int x = 0; x < 4; x++)
                activeCopyMagic(x, y);
        gameTime++;
    }
    cout << sumAll();
    return 0;
}
