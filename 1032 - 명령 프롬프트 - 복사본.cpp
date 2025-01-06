#include <iostream>
using namespace std;
typedef long long ll;
ll N, A[1000001], B, C, S;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N; S = N;
    for (int i = 0; i < N; i++)
        cin >> A[i];
    cin >> B >> C;
    for (int i = 0; i < N; i++)
        S += (A[i] - B) > 0 ? ((A[i] - B) / C + ((A[i] - B) % C == 0 ? 0 : 1)) : 0;
    cout << S;
    return 0;
}
