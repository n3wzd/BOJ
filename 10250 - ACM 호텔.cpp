#include <iostream>
#include <string>
using namespace std;
string res[10000];

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int H, W, N;
		int first;
		string second;
		cin >> H >> W >> N;

		first = N % H;
		if (first == 0)
		{
			first = H;
			second = to_string(N / H);
		}
		else second = to_string(N / H + 1);
		if (second.length() == 1) second = "0" + second;

		res[i] = to_string(first) + second;
	}
	for (int i = 0; i < n; i++) cout << res[i] << endl;
	return 0;
}