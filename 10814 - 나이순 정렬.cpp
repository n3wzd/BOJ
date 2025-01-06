#include <iostream>
#include <algorithm>
using namespace std;

class User {
public:
	int age;
	char name[105];
};

int n;
User arr[100002];

bool cmp(User a, User b) {
	return a.age < b.age;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		scanf("%d %s", &arr[i].age, &arr[i].name);
	stable_sort(arr, arr + n, cmp);
	for (int i = 0; i < n; i++)
		printf("%d %s\n", arr[i].age, arr[i].name);
	return 0;
}