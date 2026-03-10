#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<pair<int, string>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].second >> v[i].first;
    }

    sort(v.begin(), v.end(), [](const auto& a, const auto& b) {
        if (a.first != b.first) return a.first > b.first;
        return a.second < b.second;
    });

    for (int i = 0; i < n; i++) {
        cout << i + 1 << " " << v[i].second << " " << v[i].first << "\n";
    }

    return 0;
}
