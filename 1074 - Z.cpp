#include <iostream>
#include <cmath>
using namespace std;
int N, R, C;

int ZZZ(int x, int y, int n) {
    if (n == 0) return 0;
    int d = pow(2, n - 1), Z = d * d;
    if (x < d && y < d) Z *= 0;
    else if (y < d) Z *= 1;
    else if (x < d) Z *= 2;
    else Z *= 3;
    return ZZZ(x % d, y % d, n - 1) + Z;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> R >> C;
    cout << ZZZ(C, R, N);
	return 0;
}
