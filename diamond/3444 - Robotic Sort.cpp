#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
int N;
struct Node {
	Node* l, * r, * p;
	int size = 1;
	bool flip = 0;

	Node() { l = r = p = nullptr; }
	~Node() { 
		if (l) delete l;
		if (r) delete r;
	}
	void update() {
		size = 1;
		if (l) {
			l->propagate();
			size += l->size;
		}
		if (r) {
			r->propagate();
			size += r->size;
		}
	}
	void propagate() {
		if (!flip) return;
		swap(l, r);
		if (l) l->flip ^= 1;
		if (r) r->flip ^= 1;
		flip = 0;
	}
};
Node* root;

struct Robotic {
	Node* p;
	int key, id;
};
Robotic robotic[100002];

bool cmp(Robotic a, Robotic b) {
	return (a.key != b.key) ? a.key < b.key : a.id < b.id;
}

struct SplayMethod {
	void Rotate(Node* x) {
		Node* p = x->p, * c, * pp;
		if (!p) return;

		if (p->l == x) {
			p->l = c = x->r;
			x->r = p;
		}
		else {
			p->r = c = x->l;
			x->l = p;
		}
		if (c) c->p = p;

		x->p = pp = p->p;
		p->p = x;
		if (!pp) root = x;
		else if (pp->l == p) pp->l = x;
		else pp->r = x;

		p->update();
		x->update();
	}

	void Splay(Node* x) {
		while (x->p) {
			Node* p = x->p, * pp = p->p;
			if (!pp)
				Rotate(x);
			else if ((pp->l == p) == (p->l == x)) {
				Rotate(p);
				Rotate(x);
			}
			else {
				Rotate(x);
				Rotate(x);
			}
		}
	}

	void Find(int k) {
		Node* x = root;
		x->propagate();
		while (1) {
			while (x->l && x->l->size > k)
				x = x->l, x->propagate();
			if (x->l) k -= x->l->size;
			if (!k--) break;
			x = x->r;
			x->propagate();
		}
		Splay(x);
	}

	int PathUpdate(Node* x) {
		stack<Node*> path;
		Node* v = x; path.push(v);
		while (v->p) {
			v = v->p;
			path.push(v);
		}

		int sz = 0;
		v = path.top(); path.pop();
		while (!path.empty()) {
			v->propagate();
			v = path.top(); path.pop();
			if (v == v->p->r) {
				if(v->p->l)
					sz += v->p->l->size;
				sz++;
			}
		}
		v->propagate();
		if (v->l) sz += v->l->size;

		return sz;
	}

	Node* Range(int lo, int hi) {
		Find(hi + 1);
		Node* R = root;
		root = root->l;
		root->p = nullptr;

		Find(lo - 1);
		R->l = root;
		root->p = R;
		root = R;
		return root->l->r;
	}

	void Create() {
		Node* x = root = new Node();
		for (int i = 0; i < N; i++) {
			int num; cin >> num;
			x->r = new Node();
			x->r->p = x;
			x = x->r;
			robotic[i] = { x, num, i };
		}
		x->r = new Node();
		x->r->p = x;

		while (x) {
			x->update();
			x = x->p;
		}
		sort(robotic, robotic + N, cmp);
	}

	void Delete() { delete root; }
} splay;

void Flip(int lo, int hi) {
	splay.Range(lo, hi)->flip ^= 1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	while (1) {
		cin >> N;
		if (N == 0) return 0;

		splay.Create();
		for (int i = 0; i < N; i++) {
			int k = splay.PathUpdate(robotic[i].p);
			cout << k << " ";
			Flip(i + 1, k);
		}
		cout << "\n";
		splay.Delete();
	}
	return 0;
}
