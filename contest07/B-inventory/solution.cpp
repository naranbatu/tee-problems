#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    cin >> q;

    map<string, long long> inv;

    while (q--) {
        string op;
        cin >> op;

        if (op == "ADD") {
            string name; long long cnt;
            cin >> name >> cnt;
            inv[name] += cnt;
        } else if (op == "REMOVE") {
            string name; long long cnt;
            cin >> name >> cnt;
            if (inv[name] < cnt) {
                cout << "NOT_ENOUGH\n";
            } else {
                inv[name] -= cnt;
                if (inv[name] == 0) inv.erase(name);
            }
        } else if (op == "COUNT") {
            string name;
            cin >> name;
            cout << inv[name] << "\n";
            if (inv[name] == 0) inv.erase(name);
        } else {
            if (inv.empty()) {
                cout << "EMPTY\n";
            } else {
                string best = "";
                long long bestCnt = -1;
                for (auto& [name, cnt] : inv) {
                    if (cnt > bestCnt || (cnt == bestCnt && name < best)) {
                        best = name;
                        bestCnt = cnt;
                    }
                }
                cout << best << " " << bestCnt << "\n";
            }
        }
    }

    return 0;
}
