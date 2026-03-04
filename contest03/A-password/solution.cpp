#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    bool hasUpper = false, hasLower = false, hasDigit = false;
    for (char c : s) {
        if (c >= 'A' && c <= 'Z') hasUpper = true;
        if (c >= 'a' && c <= 'z') hasLower = true;
        if (c >= '0' && c <= '9') hasDigit = true;
    }

    if ((int)s.size() >= 8 && hasUpper && hasLower && hasDigit) {
        cout << "STRONG" << endl;
    } else {
        cout << "WEAK" << endl;
    }

    return 0;
}
