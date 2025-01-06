#include <iostream>
#include <cmath>
typedef long double ld;
using namespace std;
const ld PI = 3.14159265358979323846;
int Q, N;

void Solve() {
	ld A, B;
	scanf("%Lf%Lf%d", &A, &B, &N);
	
	ld r = (A + B - sqrt(A * A + B * B)) / 2;
	ld d[3] = {
		sqrt(r * r + (A - r) * (A - r)),
		sqrt(r * r + (B - r) * (B - r)),
		sqrt(r * r + r * r)
	};
	ld r1[3] = { r, r, r };

	ld max_r = r;
	int max_idx = 0;
	for (int i = 1; i < N; i++) {
		max_r = 0, max_idx = 0;
		for (int t = 0; t < 3; t++) {
			ld r2 = r1[t] * (d[t] - r1[t]) / (d[t] + r1[t]);
			if(r2 > max_r) {
				max_r = r2;
				max_idx = t;
			}
		}
		d[max_idx] -= r1[max_idx] + max_r;
		r1[max_idx] = max_r;
	}
	printf("%.8Lf\n", max_r * max_r * PI);
}

int main() {
	scanf("%d", &Q);
	while (Q--)
		Solve();
	return 0;
}
