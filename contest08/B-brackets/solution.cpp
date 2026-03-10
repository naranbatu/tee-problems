#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;

        stack<char> st;
        bool ok = true;

        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
            } else {
                if (st.empty()) { ok = false; break; }
                char top = st.top(); st.pop();
                if (c == ')' && top != '(') { ok = false; break; }
                if (c == ']' && top != '[') { ok = false; break; }
                if (c == '}' && top != '{') { ok = false; break; }
            }
        }

        if (!st.empty()) ok = false;
        cout << (ok ? "YES" : "NO") << "\n";
    }

    return 0;
}
