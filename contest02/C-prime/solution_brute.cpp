#include <bits/stdc++.h>
using namespace std;

// Brute force: Subtask 1, 2-г авна. Subtask 3 дээр TLE болно.
// T=10000, N=10^9 бол давталт 2-оос N хүртэл -> TLE!
// Зөв шийдэл: 2-оос sqrt(N) хүртэл шалгах
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        if (n < 2) {
            cout << "NO\n";
            continue;
        }
        bool prime = true;
        for (long long i = 2; i < n; i++) {
            if (n % i == 0) {
                prime = false;
                break;
            }
        }
        cout << (prime ? "YES" : "NO") << "\n";
    }
    return 0;
}
