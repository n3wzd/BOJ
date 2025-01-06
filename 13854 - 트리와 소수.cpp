#include <iostream>
#include <vector>
#include <cmath>
#include <complex>
#include <memory.h>
#include <algorithm>
#define PI 3.14159265358979323846
using namespace std;
typedef complex<double> cd;
const int SIZE = 50002;
int N, px = 0, py = 0, sz[SIZE];
vector<int> con[SIZE];
vector<cd> subDist, allDist;
bool visited[SIZE];
bool cmp(int a, int b) { return sz[a] < sz[b]; }

struct FFTkit {
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

	void MUL(vector<cd> A, vector<cd> B, vector<cd>& C) {
		int new_size = 1;
		while (new_size < A.size() + B.size())
			new_size *= 2;
		A.resize(new_size);
		B.resize(new_size);
		C.resize(new_size);

		FFT(A, 0);
		FFT(B, 0);
		for (int k = 0; k < new_size; k++)
			C[k] = A[k] * B[k];
		FFT(C, 1);
	}
} fft;

struct PrimeKit {
	bool prime[SIZE];
	void Init(int n) {
		memset(prime, 0, sizeof(prime));
		prime[1] = prime[0] = 1;
		int sq = sqrt(n);
		for (int i = 2; i <= sq; i++) {
			int d = i * 2;
			while (d <= n) {
				prime[d] = 1;
				d += i;
			}
		}
	}
	bool isPrime(int n) { return !prime[n]; }
} prime;

int SetSize(int v, int prev, int d) {
	sz[v] = 1;
	for (auto i : con[v])
		if (i != prev && !visited[i])
			sz[v] += SetSize(i, v, d + 1);
	return sz[v];
}

int Centroid(int v, int prev, int size) {
	for (auto i : con[v])
		if (i != prev && !visited[i] && sz[i] * 2 > size)
			return Centroid(i, v, size);
	return v;
}

void Race(int v, int prev, int depth) {
	if (depth >= subDist.size())
		subDist.resize(depth + 1);
	subDist[depth] += 1;

	for (auto i : con[v])
		if (i != prev && !visited[i])
			Race(i, v, depth + 1);
}

void DC(int root) {
	int size = SetSize(root, -1, 0);
	int ctr = Centroid(root, -1, size);
	visited[ctr] = 1;

	int aa = 0;
	allDist.clear();
	allDist.push_back(cd(1, 0));
	sort(con[ctr].begin(), con[ctr].end(), cmp);
	for (auto i : con[ctr]) {
		if (visited[i])
			continue;
		subDist.clear();
		Race(i, ctr, 1);

		vector<cd> mul;
		fft.MUL(subDist, allDist, mul);
		for (int n = 0; n < mul.size(); n++) {
			int c = round(mul[n].real());
			py += c;
			if (prime.isPrime(n))
				px += c;
		}

		if (allDist.size() < subDist.size())
			allDist.resize(subDist.size());
		for (int j = 0; j < subDist.size(); j++)
			allDist[j] += subDist[j];
	}

	for (auto i : con[ctr])
		if (!visited[i])
			DC(i);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cout << fixed; cout.precision(8);
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		con[a].push_back(b);
		con[b].push_back(a);
	}
	prime.Init(N);
	DC(1);
	cout << (double)px / py;
	return 0;
}
