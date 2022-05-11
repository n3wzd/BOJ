#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, W, H;
	cin >> N >> W >> H;
	while (N--)
	{
		int match;
		cin >> match;
		if (match * match <= W * W + H * H) cout << "DA" << "\n";
		else cout << "NE" << "\n";
	}
	return 0;
}
