#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long n, k;
        cin >> n >> k;
        long long m = n / k;
        // sum = k + 2k + ... + mk = k * m * (m+1) / 2
        long long km = k * m; // km <= n, fits in long long
        long long sum;
        if (km % 2 == 0) {
            sum = (km / 2) * (m + 1);
        } else {
            sum = km * ((m + 1) / 2);
        }
        cout << sum << "\n";
    }
    return 0;
}
