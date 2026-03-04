#include <bits/stdc++.h>
using namespace std;

int main() {
    long long y;
    int m;
    cin >> y >> m;

    if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) {
        cout << 31 << endl;
    } else if (m == 4 || m == 6 || m == 9 || m == 11) {
        cout << 30 << endl;
    } else {
        // February
        bool leap = (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
        if (leap) {
            cout << 29 << endl;
        } else {
            cout << 28 << endl;
        }
    }
    return 0;
}
