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
        int x;
        cin >> x;
        auto it = lower_bound(a.begin(), a.end(), x);
        if (it != a.end() && *it == x) {
            cout << (it - a.begin() + 1) << "\n";
        } else {
            cout << "-1\n";
        }
    }

    return 0;
}
