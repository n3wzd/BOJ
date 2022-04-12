#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, C, cnt = 0;
int items[32];
vector<int> setA, setB;

void BT(int start, int end, int cap, int type)
{
	if (cap < 0) return;
	if (end == start)
	{
		if(type == 1) setA.push_back(cap);
		else setB.push_back(cap);
		return;
	}
	BT(start, end - 1, cap, type);
	BT(start, end - 1, cap - items[end], type);
}

int main()
{
	cin >> N >> C;
	for(int i = 1; i <= N; i++)
		scanf("%d", &items[i]);
	
	BT(0, N / 2, C, 1);
	BT(N / 2, N, C, 2);

	sort(setB.begin(), setB.end());
	int lenA = setA.size(), lenB = setB.size();
	for (int i = 0; i < lenA; i++)
	{
		vector<int>::iterator lo = lower_bound(setB.begin(), setB.end(), C - setA[i]);
		cnt += setB.end() - lo;
	}

	cout << cnt << endl;
	return 0;
}