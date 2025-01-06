#include <iostream>
using namespace std;

class Mass
{
public:
	int w;
	int h;
	int rank;

	Mass(int w, int h)
	{
		this->w = w;
		this->h = h;
		rank = 1;
	}

	bool IsLower(Mass* m) // if lower than m, return true
	{
		return (w < m->w && h < m->h) ? true : false;
	}
};

Mass* mass[50];

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int w, h;
		cin >> w >> h;
		mass[i] = new Mass(w, h);
	}
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if(mass[i]->IsLower(mass[j])) mass[i]->rank += 1;

	for (int i = 0; i < n; i++)
		printf("%d ", mass[i]->rank);

	return 0;
}