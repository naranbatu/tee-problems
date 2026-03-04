#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    unordered_map<string, string> dict;
    for (int i = 0; i < n; i++) {
        string a, b;
        cin >> a >> b;
        dict[a] = b;
        dict[b] = a;
    }

    while (q--) {
        string w;
        cin >> w;
        if (dict.count(w)) {
            cout << dict[w] << "\n";
        } else {
            cout << "UNKNOWN\n";
        }
    }

    return 0;
}
