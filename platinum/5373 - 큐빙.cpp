#include <iostream>
using namespace std;
struct ShiftList { int id[4], idx[4][3]; };
int T, K;
char cube[6][9], boardTmp[9], color[6] = { 'w', 'y', 'r', 'o', 'g', 'b' };
ShiftList SL[6] = { { { 2, 5, 3, 4 }, { 0, 1, 2, 0, 1, 2, 0, 1, 2, 0, 1, 2 } },
    { { 3, 5, 2, 4 }, { 8, 7, 6, 8, 7, 6, 8, 7, 6, 8, 7, 6 } },
    { { 1, 5, 0, 4 }, { 0, 1, 2, 6, 3, 0, 8, 7, 6, 2, 5, 8 } },
    { { 0, 5, 1, 4 }, { 0, 1, 2, 2, 5, 8, 8, 7, 6, 6, 3, 0 } },
    { { 1, 2, 0, 3 }, { 6, 3, 0, 6, 3, 0, 6, 3, 0, 2, 5, 8 } },
    { { 1, 3, 0, 2 }, { 2, 5, 8, 6, 3, 0, 2, 5, 8, 2, 5, 8 } }
};

int getCubeValue(int org, int id, int idx) {
    return cube[SL[org].id[id]][SL[org].idx[id][idx]];
}

void setCubeValue(int org, int id, int idx, int value) {
    cube[SL[org].id[id]][SL[org].idx[id][idx]] = value;
}

void cubeShift(int org, char dire) {
    char tmp[3];
    for (int i = 0; i < 3; i++)
        tmp[i] = getCubeValue(org, 0, i);
    if (dire == '+') {
        for (int d = 0; d < 3; d++)
            for (int i = 0; i < 3; i++)
                setCubeValue(org, d, i, getCubeValue(org, d + 1, i));
        for (int i = 0; i < 3; i++)
            setCubeValue(org, 3, i, tmp[i]);
    }
    else {
        for (int d = 4; d > 1; d--)
            for (int i = 0; i < 3; i++)
                setCubeValue(org, d % 4, i, getCubeValue(org, (d + 3) % 4, i));
        for (int i = 0; i < 3; i++)
            setCubeValue(org, 1, i, tmp[i]);
    }
}

void cubeRotate(int org, char dire) {
    int d = dire == '+' ? 1 : -1;
    for (int p = 0; p < 9; p++) {
        int dx = 1 - (p % 3), dy = 1 - (p / 3);
        int nx = 1 + dy * d, ny = 1 - dx * d;
        boardTmp[ny * 3 + nx] = cube[org][p];
    }
    for (int p = 0; p < 9; p++)
        cube[org][p] = boardTmp[p];
}

void init() {
    for (int org = 0; org < 6; org++)
        for (int p = 0; p < 9; p++)
            cube[org][p] = color[org];
}

void print() {
    for (int p = 0; p < 9; p++) {
        cout << cube[0][p];
        if (p % 3 == 2)
            cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    while (T--) {
        init(); cin >> K;
        while (K--) {
            int org = 0; string s; cin >> s;
            if (s[0] == 'U') org = 0;
            if (s[0] == 'D') org = 1;
            if (s[0] == 'F') org = 2;
            if (s[0] == 'B') org = 3;
            if (s[0] == 'L') org = 4;
            if (s[0] == 'R') org = 5;
            cubeRotate(org, s[1]);
            cubeShift(org, s[1]);
        }
        print();
    }
    return 0;
}
