#include <iostream>
using namespace std;
int N, M, T;
int start[52], board[52][52], dx[4] = { 1, 0, -1, 0 }, dm[4] = { 0, 1, 0, -1 };
bool eraseMark[52][52], eraseMarkTemp[52][52];
int mToIdx(int x, int m) { return (m - start[x] + M) % M; }

void rotate(int x, int k) {
    start[x] = (start[x] + k + M) % M;
}

void erase() {
    for(int x = 0; x < N; x++) {
        for(int m = 0; m < M; m++) {
            if(eraseMark[x][mToIdx(x, m)])
                continue;
            for(int d = 0; d < 4; d++) {
                if((d == 2 && x == 0) || (d == 0 && x == N - 1))
                    continue;
                int nx = x + dx[d], nm = (m + dm[d]) % M;
                if(eraseMark[nx][mToIdx(nx, nm)])
                    continue;
                eraseMarkTemp[x][mToIdx(x, m)] |= board[x][mToIdx(x, m)] == board[nx][mToIdx(nx, nm)];
            }
        }
    }
    for(int x = 0; x < N; x++)
        for(int m = 0; m < M; m++)
            eraseMark[x][m] = eraseMarkTemp[x][m];
}

void update() {
    int cnt = 0;
    double average = 0;
    for(int x = 0; x < N; x++)
        for(int m = 0; m < M; m++)
            if(!eraseMark[x][m])
                cnt++, average += board[x][m];
    average /= cnt;
    for(int x = 0; x < N; x++)
        for(int m = 0; m < M; m++)
            if(!eraseMark[x][m])
                board[x][m] += board[x][m] < average ? 1 : (board[x][m] > average ? -1 : 0);
}

int sum() {
    int sum = 0;
    for(int x = 0; x < N; x++)
        for(int m = 0; m < M; m++)
            if(!eraseMark[x][m])
                sum += board[x][m];
    return sum;
}

void print() {
    for(int x = 0; x < N; x++) {
        for(int m = 0; m < M; m++)
            cout << board[x][mToIdx(x, m)] << " ";
        cout << "\n";
    }
    cout << "\n";
}

void print2() {
    for(int x = 0; x < N; x++) {
        for(int m = 0; m < M; m++)
            cout << eraseMark[x][mToIdx(x, m)] << " ";
        cout << "\n";
    }
    cout << "\n";
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> T;
    for(int x = 0; x < N; x++)
        for(int m = 0; m < M; m++)
            cin >> board[x][m];
	while (T--) {
		int x, d, k;
		cin >> x >> d >> k;
		for(int i = 0; i < N; i++)
            rotate(x * i - 1, k * (d == 0 ? 1 : -1));
        print();
        erase(); update();
        print();
	}
	cout << sum();
	return 0;
}
