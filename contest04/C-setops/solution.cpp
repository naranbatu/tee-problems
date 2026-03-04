#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    cin >> q;

    set<int> s;

    while (q--) {
        string op;
        cin >> op;

        if (op == "ADD") {
            int x; cin >> x;
            s.insert(x);
        } else if (op == "REMOVE") {
            int x; cin >> x;
            s.erase(x);
        } else if (op == "CHECK") {
            int x; cin >> x;
            cout << (s.count(x) ? "YES" : "NO") << "\n";
        } else {
            cout << s.size() << "\n";
        }
    }

    return 0;
}
