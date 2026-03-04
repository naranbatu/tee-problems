#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    while (q--) {
        int l, r;
        cin >> l >> r;
        l--; r--;

        vector<int> sub(a.begin() + l, a.begin() + r + 1);
        sort(sub.begin(), sub.end());

        int sz = sub.size();
        cout << sub[(sz - 1) / 2] << "\n";
    }

    return 0;
}
