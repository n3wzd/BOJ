#include <iostream>
#include <vector>
#include <cmath>
#include <complex>
#define PI 3.14159265358979323846
using namespace std;
typedef long long ll;
typedef complex<double> cd;
const int SIZE = 1 << 17;
const int base = 30000;

void FFT(vector<cd>& A, bool inv) {
	int n = A.size();
	for (int k = 0; k < n; k++) {
		int i = 0, lo = 1, hi = n >> 1;
		for (; lo < hi; lo <<= 1, hi >>= 1) {
			if (k & hi) i += lo;
			if (k & lo) i += hi;
		}
		if (lo == hi && (k & hi))
			i += lo;
		if (k < i)
			swap(A[k], A[i]);
	}

	for (int size = 2; size <= n; size *= 2) {
		double x = 2 * PI / size * (inv ? -1 : 1);
		cd w0 = cd(cos(x), sin(x));
		for (int i = 0; i < n; i += size) {
			cd w = cd(1, 0);
			for (int j = 0; j < size / 2; j++) {
				cd tmp = A[(size / 2) + i + j] * w;
				A[(size / 2) + i + j] = A[i + j] - tmp;
				A[i + j] += tmp;
				w *= w0;
			}
		}
	}
	if (inv)
		for (int i = 0; i < n; i++)
			A[i] /= n;
}

void MUL(vector<cd>& A, vector<cd>& B, vector<cd>& C) {
	FFT(A, 0);
	FFT(B, 0);
	for (int i = 0; i < A.size(); i++)
		C[i] = A[i] * B[i];
	FFT(C, 1);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N1, N2, N3, d;
	vector<cd> A(SIZE), B(SIZE), C(SIZE);
	vector<int> goal;
	cin >> N1;
	for (int i = 0; i < N1; i++) {
		cin >> d;
		A[d + base] = cd(1, 0);
	}
	cin >> N2;
	for (int i = 0; i < N2; i++) {
		cin >> d;
		goal.push_back((d + base) * 2);
	}
	cin >> N3;
	for (int i = 0; i < N3; i++) {
		cin >> d;
		B[d + base] = cd(1, 0);
	}

	ll cnt = 0;
	MUL(A, B, C);
	for (int i = 0; i < goal.size(); i++)
		cnt += round(C[goal[i]].real());
	cout << cnt;
	return 0;
}
