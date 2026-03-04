#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    cin >> q;

    stack<string> backStack, fwdStack;
    string current = "home";

    while (q--) {
        string op;
        cin >> op;

        if (op == "VISIT") {
            string url;
            cin >> url;
            backStack.push(current);
            current = url;
            while (!fwdStack.empty()) fwdStack.pop();
        } else if (op == "BACK") {
            if (backStack.empty()) {
                cout << "IGNORE\n";
            } else {
                fwdStack.push(current);
                current = backStack.top();
                backStack.pop();
                cout << current << "\n";
            }
        } else if (op == "FORWARD") {
            if (fwdStack.empty()) {
                cout << "IGNORE\n";
            } else {
                backStack.push(current);
                current = fwdStack.top();
                fwdStack.pop();
                cout << current << "\n";
            }
        } else {
            cout << current << "\n";
        }
    }

    return 0;
}
