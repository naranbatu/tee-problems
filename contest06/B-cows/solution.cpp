#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, c;
    cin >> n >> c;

    vector<long long> pos(n);
    for (int i = 0; i < n; i++) cin >> pos[i];
    sort(pos.begin(), pos.end());

    auto canPlace = [&](long long minDist) -> bool {
        int placed = 1;
        long long last = pos[0];
        for (int i = 1; i < n; i++) {
            if (pos[i] - last >= minDist) {
                placed++;
                last = pos[i];
                if (placed >= c) return true;
            }
        }
        return false;
    };

    long long lo = 1, hi = pos[n - 1] - pos[0], ans = 0;
    while (lo <= hi) {
        long long mid = lo + (hi - lo) / 2;
        if (canPlace(mid)) {
            ans = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    cout << ans << endl;

    return 0;
}
