#include <iostream>
#include <queue>
using namespace std;
struct Point { int x, y; };
int N, M, genX, genY, genId, genDire, beadCnt, score, board[52][52];
int dx[4] = { -1, 0, 1, 0, }, dy[4] = { 0, 1, 0, -1 }, changeDire[4] = { 3, 1, 0, 2 };
deque<int> beads;
bool isDestroiedBead[2502];

void sandstorm() {
    if (board[genY][genX] > 0)
        beads.push_back(board[genY][genX]);
    board[genY][genX] = ++genId;
}

void proceed(int dist) {
    for (int w = 1; w <= dist; w++) {
        genX += dx[genDire], genY += dy[genDire];
        sandstorm();
    }
    genDire = (genDire + 1) % 4;
}

void whirlwind() {
    for (int i = 1; i < N; i++)
        for (int t = 0; t < 2; t++)
            proceed(i);
    proceed(N - 1);
}

int getScore(int bead, int combo, int maxCombo) {
    if (combo >= 4) {
        score += bead * combo;
        for (int c = 0; c < combo; c++)
            beads.pop_back();
    }
    return max(combo, maxCombo);
}

int explosion() {
    int size = beads.size(), combo = 1, prevBead = -1, maxCombo = 1;
    while (size--) {
        int bead = beads.front(); beads.pop_front();
        if (prevBead == bead)
            combo++;
        else {
            maxCombo = getScore(prevBead, combo, maxCombo);
            combo = 1;
        }
        prevBead = bead;
        beads.push_back(bead);
    }
    maxCombo = getScore(prevBead, combo, maxCombo);
    return maxCombo;
}

void addBead(int b) {
    if (beadCnt++ < N * N - 1)
        beads.push_back(b);
}

void copyBead(int bead, int combo) {
    if (bead != -1) {
        addBead(combo);
        addBead(bead);
    }
}

void clone() {
    int size = beads.size(), combo = 1, prevBead = -1;
    beadCnt = 0;
    while (size--) {
        int bead = beads.front(); beads.pop_front();
        if (prevBead == bead)
            combo++;
        else {
            copyBead(prevBead, combo);
            combo = 1;
        }
        prevBead = bead;
    }
    copyBead(prevBead, combo);
}

void blizzardMagic(int d, int s) {
    int size = beads.size();
    for (int ds = 1; ds <= s; ds++) {
        int x = N / 2 + dx[d] * ds, y = N / 2 + dy[d] * ds;
        if (board[y][x] <= size)
            isDestroiedBead[board[y][x]] = 1;
    }
    for (int i = 1; i <= size; i++) {
        if (!isDestroiedBead[i])
            beads.push_back(beads.front());
        beads.pop_front();
        isDestroiedBead[i] = 0;
    }
    while (explosion() >= 4);
    clone();
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M; genX = N / 2, genY = N / 2;
    for (int y = 0; y < N; y++)
        for (int x = 0; x < N; x++)
            cin >> board[y][x];
    whirlwind();
    while (M--) {
        int d, s;
        cin >> d >> s;
        blizzardMagic(changeDire[d - 1], s);
    }
    cout << score;
    return 0;
}
