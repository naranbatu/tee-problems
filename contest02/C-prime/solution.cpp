#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

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
        for (long long i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                prime = false;
                break;
            }
        }
        cout << (prime ? "YES" : "NO") << "\n";
    }
    return 0;
}
