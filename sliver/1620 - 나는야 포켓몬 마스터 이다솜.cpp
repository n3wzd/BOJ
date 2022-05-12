#include <iostream>
#include <string>
#include <map>
using namespace std;

int N, M;
map<string, int> pkmSet;
string pkmList[100001];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		string pokemon;
		cin >> pokemon;
		pkmSet.insert(make_pair(pokemon, i));
		pkmList[i] = pokemon;
	}
	for (int i = 0; i < M; i++)
	{
		string q;
		cin >> q;
		if (q[0] >= '0' && q[0] <= '9')
		{
			int code = stoi(q);
			cout << pkmList[code] << "\n";
		}
		else cout << pkmSet.find(q)->second << "\n";
	}
	return 0;
}