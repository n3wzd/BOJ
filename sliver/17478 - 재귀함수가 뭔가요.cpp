#include <iostream>
using namespace std;

int N;

void PrintLine(int n)
{
	for(int i = N - n; i > 0; i--)
		printf("____");
}

void WhatIsRecursion(int n)
{
	PrintLine(n), printf("\"����Լ��� ������?\"\n");
	if (n == 0)
	{
		PrintLine(n), printf("\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n");
	}
	else
	{
		PrintLine(n), printf("\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n");
		PrintLine(n), printf("���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n");
		PrintLine(n), printf("���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n");
	}
	if(n > 0) WhatIsRecursion(n - 1);
	PrintLine(n), printf("��� �亯�Ͽ���.\n");
}

int main()
{
	cin >> N;
	printf("��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n");
	WhatIsRecursion(N);
	return 0;
}