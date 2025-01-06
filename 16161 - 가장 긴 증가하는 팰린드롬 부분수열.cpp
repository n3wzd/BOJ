#include <iostream>
using namespace std;
int N, pal = 1, pal_local = 0;
int com_state = 0;
int arr[100002];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> arr[0];
	for (int i = 1; i < N; i++) {
		cin >> arr[i];
		if (com_state == 0) {
			if (arr[i - 1] >= arr[i]) {
				com_state = 1;
				pal_local = 1;
				if (arr[i - 1] == arr[i])
					pal_local++;
				else if (i - 2 >= 0 && arr[i - 2] == arr[i])
					pal_local += 2;
				else {
					com_state = 0;
					pal_local = 0;
				}
			}
		}
		else if(com_state == 1){
			if (i - (pal_local + 1) >= 0 && arr[i - (pal_local + 1)] == arr[i] && arr[i - 1] > arr[i])
				pal_local += 2;
			else {
				com_state = 0;
				pal = max(pal, pal_local);
				pal_local = 0;
			}
		}
	}
	pal = max(pal, pal_local);
	cout << pal;
	return 0;
}
