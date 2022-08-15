#include <iostream>
#include <algorithm>
using namespace std;
int N = 9, key[9], sum = 0;
void Print(int a, int b) {
	for (int i = 0; i < N; i++)
		if (i != a && i != b)
			cout << key[i] << "\n";
	exit(0);
}

int main() {
	for (auto& k : key) {
		cin >> k;
		sum += k;
	}
	sort(key, key + N);
	for (int i = 0; i < N; i++)
		for (int j = i + 1; j < N; j++)
			if (sum - (key[i] + key[j]) == 100)
				Print(i, j);
	return 0;
}
