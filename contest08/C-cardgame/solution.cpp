#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    queue<int> q1, q2;
    for (int i = 0; i < n; i++) { int x; cin >> x; q1.push(x); }
    for (int i = 0; i < n; i++) { int x; cin >> x; q2.push(x); }

    int rounds = 0;
    while (!q1.empty() && !q2.empty() && rounds < 1000000) {
        int c1 = q1.front(); q1.pop();
        int c2 = q2.front(); q2.pop();
        rounds++;

        if (c1 >= c2) {
            q1.push(c1);
            q1.push(c2);
        } else {
            q2.push(c2);
            q2.push(c1);
        }
    }

    if (rounds >= 1000000) cout << "DRAW\n";
    else if (q2.empty()) cout << "1 " << rounds << "\n";
    else cout << "2 " << rounds << "\n";

    return 0;
}
