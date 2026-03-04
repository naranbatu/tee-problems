#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    map<int, int> freq;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        freq[a[i]]++;
    }

    set<int> result;
    for (auto& [val, cnt] : freq) {
        if (cnt == 1) result.insert(val);
    }

    if (result.empty()) {
        cout << "EMPTY" << endl;
    } else {
        bool first = true;
        for (int x : result) {
            if (!first) cout << " ";
            cout << x;
            first = false;
        }
        cout << endl;
    }

    return 0;
}
