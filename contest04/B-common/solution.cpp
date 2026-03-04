#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    set<int> sa;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        sa.insert(x);
    }

    set<int> common;
    for (int i = 0; i < m; i++) {
        int x; cin >> x;
        if (sa.count(x)) common.insert(x);
    }

    if (common.empty()) {
        cout << "EMPTY" << endl;
    } else {
        bool first = true;
        for (int x : common) {
            if (!first) cout << " ";
            cout << x;
            first = false;
        }
        cout << endl;
    }

    return 0;
}
