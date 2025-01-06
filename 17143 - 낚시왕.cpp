#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Shark {
	int x, y, size, dire, axis, speed;
	Shark* next = nullptr;
	Shark* prev = nullptr;
};
int R, C, M, score, direList[4] = { -1, 1, 1, -1 };
vector<Shark> inputShark;
Shark* rootShark;
Shark* boardShark[102][102];

void createDS() {
	sort(inputShark.begin(), inputShark.end(), [](const Shark& a, const Shark& b) { return a.size < b.size; });
	Shark* prevNode = rootShark = &inputShark[0];
	boardShark[prevNode->y][prevNode->x] = prevNode;
	for (int i = 1; i < M; i++) {
		Shark* curNode = &inputShark[i];
		boardShark[curNode->y][curNode->x] = curNode;
		prevNode->next = curNode;
		curNode->prev = prevNode;
		prevNode = curNode;
	}
}

void deleteSharkList(Shark* node) {
	Shark* prevNode = node->prev;
	Shark* nextNode = node->next;
	if (prevNode != nullptr)
		prevNode->next = nextNode;
	if (nextNode != nullptr)
		nextNode->prev = prevNode;
	if (node == rootShark)
		rootShark = nextNode;
}

void fishing(int x) {
	for (int y = 0; y < R; y++) {
		if (boardShark[y][x] != nullptr) {
			Shark* catched = boardShark[y][x];
			score += catched->size;
			deleteSharkList(catched);
			boardShark[y][x] = nullptr;
			break;
		}
	}
}

void move(int pos, int bound, int d, int s, Shark* node) {
	s %= (bound * 2);
	while (s > 0) {
		if (pos + d * s > bound) {
			s -= bound - pos;
			pos = bound;
			d *= -1;
		}
		else if (pos + d * s < 0) {
			s -= pos;
			pos = 0;
			d *= -1;
		}
		else {
			pos += d * s;
			s = 0;
		}
	}
	node->dire = d;
	node->axis == 1 ? node->y = pos : node->x = pos;
	Shark* prevShark = boardShark[node->y][node->x];
	if (prevShark != nullptr && prevShark != node && prevShark->size < node->size)
		deleteSharkList(prevShark);
	boardShark[node->y][node->x] = node;
}

void sharkSwim() {
	Shark* curNode = rootShark;
	while (curNode != nullptr) {
		int x = curNode->x, y = curNode->y, d = curNode->dire, a = curNode->axis, s = curNode->speed;
		if (boardShark[y][x] != nullptr && boardShark[y][x]->size == curNode->size)
			boardShark[y][x] = nullptr;
		a == 1 ? move(y, R - 1, d, s, curNode) : move(x, C - 1, d, s, curNode);
		curNode = curNode->next;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> R >> C >> M;
	if (M == 0) {
		cout << 0;
		return 0;
	}
	for (int i = 0; i < M; i++) {
		int r, c, s, d, z;
		cin >> r >> c >> s >> d >> z;
		inputShark.push_back({ c - 1, r - 1, z, direList[d - 1], d > 2 ? 0 : 1,  s });
	}
	createDS();
	for (int x = 0; x < C; x++) {
		fishing(x);
		sharkSwim();
	}
	cout << score;
	return 0;
}
