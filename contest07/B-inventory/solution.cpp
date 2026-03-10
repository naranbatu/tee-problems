#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    cin >> q;

    map<string, long long> inv;
    set<pair<long long, string>> s; // {-count, name} for O(log N) max

    while (q--) {
        string op;
        cin >> op;

        if (op == "ADD") {
            string name; long long cnt;
            cin >> name >> cnt;
            if (inv.count(name)) s.erase({-inv[name], name});
            inv[name] += cnt;
            s.insert({-inv[name], name});
        } else if (op == "REMOVE") {
            string name; long long cnt;
            cin >> name >> cnt;
            bool existed = inv.count(name) > 0;
            if (inv[name] < cnt) {
                if (!existed) s.insert({0, name}); // inv[name] created 0 entry
                cout << "NOT_ENOUGH\n";
            } else {
                s.erase({-inv[name], name});
                inv[name] -= cnt;
                if (inv[name] == 0) {
                    inv.erase(name);
                } else {
                    s.insert({-inv[name], name});
                }
            }
        } else if (op == "COUNT") {
            string name;
            cin >> name;
            auto it = inv.find(name);
            if (it != inv.end()) {
                cout << it->second << "\n";
                if (it->second == 0) {
                    s.erase({0, name});
                    inv.erase(it);
                }
            } else {
                cout << 0 << "\n";
            }
        } else { // MAX
            if (s.empty()) {
                cout << "EMPTY\n";
            } else {
                auto [negCnt, name] = *s.begin();
                cout << name << " " << -negCnt << "\n";
            }
        }
    }

    return 0;
}
