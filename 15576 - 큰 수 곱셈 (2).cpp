#include <iostream>
#include <vector>
#include <cmath>
#include <complex>
#define PI 3.14159265358979323846
using namespace std;
typedef long long ll;
typedef complex<double> cd;
const int SIZE = 1 << 20;

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
	vector<cd> A(SIZE), B(SIZE), C(SIZE);
	vector<char> res(SIZE);
	string num1, num2;
	cin >> num1 >> num2;
	if (num1 == "0" || num2 == "0") {
		cout << 0;
		return 0;
	}

	int len1 = num1.size(), len2 = num2.size();
	for (int i = len1 - 1; i >= 0; i--) {
		int r = num1[i] - '0';
		A[(len1 - 1) - i] = cd(r, 0);
	}
	for (int i = len2 - 1; i >= 0; i--) {
		int r = num2[i] - '0';
		B[(len2 - 1) - i] = cd(r, 0);
	}
	MUL(A, B, C);

	ll buf = 0;
	int limit = 0;
	for (int i = 0; i < SIZE; i++) {
		buf += round(C[i].real());
		res[i] = (buf % 10) + '0';
		if (res[i] != '0')
			limit = i;
		buf /= 10;
	}
	for (int i = limit; i >= 0; i--)
		cout << res[i];
	return 0;
}
