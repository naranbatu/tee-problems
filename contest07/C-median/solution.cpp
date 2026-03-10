#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

struct Node {
    int left, right, cnt;
} tree[MAXN * 40];

int root[MAXN], tot = 0;

int build(int l, int r) {
    int p = ++tot;
    tree[p].cnt = 0;
    tree[p].left = tree[p].right = 0;
    if (l == r) return p;
    int mid = (l + r) / 2;
    tree[p].left = build(l, mid);
    tree[p].right = build(mid + 1, r);
    return p;
}

int update(int prev, int l, int r, int pos) {
    int p = ++tot;
    tree[p] = tree[prev];
    tree[p].cnt++;
    if (l == r) return p;
    int mid = (l + r) / 2;
    if (pos <= mid)
        tree[p].left = update(tree[prev].left, l, mid, pos);
    else
        tree[p].right = update(tree[prev].right, mid + 1, r, pos);
    return p;
}

int query(int u, int v, int l, int r, int k) {
    if (l == r) return l;
    int mid = (l + r) / 2;
    int leftCnt = tree[tree[v].left].cnt - tree[tree[u].left].cnt;
    if (k <= leftCnt)
        return query(tree[u].left, tree[v].left, l, mid, k);
    else
        return query(tree[u].right, tree[v].right, mid + 1, r, k - leftCnt);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> sorted_a = a;
    sort(sorted_a.begin(), sorted_a.end());
    sorted_a.erase(unique(sorted_a.begin(), sorted_a.end()), sorted_a.end());
    int m = sorted_a.size();

    root[0] = build(0, m - 1);
    for (int i = 0; i < n; i++) {
        int idx = lower_bound(sorted_a.begin(), sorted_a.end(), a[i]) - sorted_a.begin();
        root[i + 1] = update(root[i], 0, m - 1, idx);
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        int sz = r - l + 1;
        int k = (sz + 1) / 2;
        int idx = query(root[l - 1], root[r], 0, m - 1, k);
        cout << sorted_a[idx] << "\n";
    }

    return 0;
}
