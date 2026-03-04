#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<long long> a(n);
    long long maxVal = 0, total = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        maxVal = max(maxVal, a[i]);
        total += a[i];
    }

    auto canSplit = [&](long long maxSum) -> bool {
        int parts = 1;
        long long curSum = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] > maxSum) return false;
            if (curSum + a[i] > maxSum) {
                parts++;
                curSum = a[i];
                if (parts > k) return false;
            } else {
                curSum += a[i];
            }
        }
        return true;
    };

    long long lo = maxVal, hi = total, ans = total;
    while (lo <= hi) {
        long long mid = lo + (hi - lo) / 2;
        if (canSplit(mid)) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    cout << ans << endl;

    return 0;
}
