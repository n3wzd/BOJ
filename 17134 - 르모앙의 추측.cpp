#include <iostream>
#include <vector>
#include <cmath>
#include <complex>
#define PI 3.14159265358979323846
using namespace std;
typedef long long ll;
typedef complex<double> cd;
const int SIZE = 1 << 21;

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

const int SIZE2 = 1000000;
bool prime[1000005];
bool isPrime(int n) { return !prime[n]; }
void PrimeScan(int n) {
	int sq = sqrt(n);
	for (int i = 2; i <= sq; i++) {
		int d = i * 2;
		while (d <= n) {
			prime[d] = 1;
			d += i;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	vector<cd> A(SIZE), B(SIZE), C(SIZE);
	int N;
	cin >> N;
	PrimeScan(SIZE2);
	for (int i = 2; i <= SIZE2; i++) {
		if (isPrime(i)) {
			A[i] = cd(1, 0);
			if(i * 2 <= SIZE2)
				B[i * 2] = cd(1, 0);
		}
	}
	MUL(A, B, C);
	while (N--) {
		int num;
		cin >> num;
		cout << round(C[num].real()) << "\n";
	}
	return 0;
}
