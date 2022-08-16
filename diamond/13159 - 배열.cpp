#include <iostream>
#include <stack>
typedef long long ll;
using namespace std;
int N, M;
struct Node {
	Node* l, * r, * p;
	int size = 1;
	ll value, sum, minV, maxV;
	bool flip = 0;

	Node(int d) {
		sum = minV = maxV = value = d;
		l = r = p = nullptr;
	}
	~Node() { 
		if (l) delete l;
		if (r) delete r;
	}
	void update() {
		size = 1;
		sum = minV = maxV = value;
		if (l) {
			l->propagate();
			size += l->size;
			sum += l->sum;
			minV = min(minV, l->minV);
			maxV = max(maxV, l->maxV);
		}
		if (r) {
			r->propagate();
			size += r->size;
			sum += r->sum;
			minV = min(minV, r->minV);
			maxV = max(maxV, r->maxV);
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
Node* pdr[300002];

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

	int GetKey(Node* x) {
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
				if (v->p->l)
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
		Node* x = root = new Node(0);
		x->maxV = 0; x->minV = N + 1;
		for (int i = 1; i <= N; i++) {
			x->r = new Node(i);
			x->r->p = x;
			x = x->r;
			pdr[i] = x;
		}
		x->r = new Node(0);
		x->r->p = x;
		x->maxV = 0; x->minV = N + 1;

		while (x) {
			x->update();
			x = x->p;
		}
	}

	void Delete() { delete root; }
} splay;

void Flip(int lo, int hi) {
	splay.Range(lo, hi)->flip ^= 1;
}

void Shift(int lo, int hi, int t) {
	int len = hi - lo + 1;
	t = (t + N / len * len + len) % len;
	if (t == 0) return;

	Flip(lo, hi);
	Flip(lo, lo + t - 1);
	Flip(lo + t, hi);
}

void DFS(Node* v) {
	if (!v) return;
	v->propagate();
	DFS(v->l);
	if(v->value != 0)
		cout << v->value << " ";
	DFS(v->r);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	splay.Create();
	for (int i = 0; i < M; i++) {
		int a, b, c, d;
		cin >> a >> b;
		if (a == 1) {
			cin >> c;
			Node* x = splay.Range(b, c);
			cout << x->minV << " " << x->maxV << " " << x->sum << "\n";
			Flip(b, c);
		}
		if (a == 2) {
			cin >> c >> d;
			Node* x = splay.Range(b, c);
			cout << x->minV << " " << x->maxV << " " << x->sum << "\n";
			Shift(b, c, d);
		}
		if (a == 3)
			cout << splay.Range(b, b)->value << "\n";
		if (a == 4) 
			cout << splay.GetKey(pdr[b]) << "\n";
	}
	DFS(root);
	splay.Delete();
	return 0;
}
