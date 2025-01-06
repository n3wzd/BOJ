#include <iostream>
#include <utility>
using namespace std;

int melon, p = -1;
pair<int, int> rect[6];

int Cycle(int idx)
{
	return (idx + 6) % 6;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> melon;
	for (int i = 0; i < 6; i++)
		cin >> rect[i].first >> rect[i].second;
	for (int i = 0; i < 6; i++)
		if (rect[Cycle(i - 2)].first == rect[i].first && p == -1)
			p = (rect[Cycle(i - 3)].first == rect[Cycle(i - 1)].first) ? Cycle(i - 1) : i;

	int big = (rect[p].second + rect[Cycle(p - 2)].second) * (rect[Cycle(p + 1)].second + rect[Cycle(p - 1)].second);
	int little = rect[p].second * rect[Cycle(p - 1)].second;
	cout << melon * (big - little);
	return 0;
}
