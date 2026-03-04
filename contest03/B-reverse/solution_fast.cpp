#include <bits/stdc++.h>
using namespace std;

mt19937 rng(42);

struct Node {
    int val, prior, sz;
    bool rev;
    Node *l, *r;

    Node(int v) : val(v), prior(rng()), sz(1), rev(false), l(nullptr), r(nullptr) {}
};

int sz(Node* t) {
    return t ? t->sz : 0;
}

void pull(Node* t) {
    if (t) t->sz = 1 + sz(t->l) + sz(t->r);
}

void push(Node* t) {
    if (t && t->rev) {
        swap(t->l, t->r);
        if (t->l) t->l->rev ^= true;
        if (t->r) t->r->rev ^= true;
        t->rev = false;
    }
}

void split(Node* t, int k, Node*& l, Node*& r) {
    if (!t) { l = r = nullptr; return; }
    push(t);
    if (sz(t->l) < k) {
        split(t->r, k - sz(t->l) - 1, t->r, r);
        l = t;
    } else {
        split(t->l, k, l, t->l);
        r = t;
    }
    pull(t);
}

void merge(Node*& t, Node* l, Node* r) {
    push(l); push(r);
    if (!l || !r) {
        t = l ? l : r;
    } else if (l->prior > r->prior) {
        merge(l->r, l->r, r);
        t = l;
    } else {
        merge(r->l, l, r->l);
        t = r;
    }
    pull(t);
}

void reverseRange(Node*& root, int l, int r) {
    Node *a, *b, *c;
    split(root, l - 1, a, b);
    split(b, r - l + 1, b, c);
    b->rev ^= true;
    merge(b, b, c);
    merge(root, a, b);
}

void print(Node* t, vector<int>& res) {
    if (!t) return;
    push(t);
    print(t->l, res);
    res.push_back(t->val);
    print(t->r, res);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    Node* root = nullptr;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        Node* node = new Node(x);
        merge(root, root, node);
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        reverseRange(root, l, r);
    }

    vector<int> res;
    res.reserve(n);
    print(root, res);

    for (int i = 0; i < n; i++) {
        if (i > 0) cout << ' ';
        cout << res[i];
    }
    cout << '\n';

    return 0;
}
