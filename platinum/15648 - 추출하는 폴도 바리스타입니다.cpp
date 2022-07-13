#include <iostream>
using namespace std;
const int SIZE = 5e5 + 3, MAXV = 5e5;
int N, K, D, coffee = 0;
int A1[SIZE];
int A2[SIZE * 4];

int Get(int start, int end, int idx, int left, int right) {
    if (start > right || end < left) return 0;
    if (start >= left && end <= right) return A2[idx];
    int mid = (start + end) / 2;
    return max(Get(start, mid, idx * 2, left, right), Get(mid + 1, end, idx * 2 + 1, left, right));
}

int Update(int start, int end, int idx, int pos, int value) {
    if (start > pos || end < pos) return A2[idx];
    if (start == end) return A2[idx] = value;
    int mid = (start + end) / 2;
    return A2[idx] = max(Update(start, mid, idx * 2, pos, value), Update(mid + 1, end, idx * 2 + 1, pos, value));
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> K >> D;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;

        int m1 = A1[num % K];
        int ran1 = (num - D >= 0) ? num - D : 0;
        int ran2 = (num + D <= MAXV) ? num + D : MAXV;
        int m2 = Get(1, MAXV, 1, ran1, ran2);

        int res = max(m1, m2) + 1;
        A1[num % K] = res;
        Update(1, MAXV, 1, num, res);
        coffee = max(coffee, res);
    }
    cout << coffee;
    return 0;
}