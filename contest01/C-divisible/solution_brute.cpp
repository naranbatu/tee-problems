#include <bits/stdc++.h>
using namespace std;

// Brute force: Subtask 1, 2-г авна. Subtask 3 дээр TLE болно.
// T=100000, N=10^9 -> 10^14 давталт -> TLE!
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n, k;
        cin >> n >> k;
        long long sum = 0;
        for (long long i = k; i <= n; i += k) {
            sum += i;
        }
        cout << sum << "\n";
    }
    return 0;
}
