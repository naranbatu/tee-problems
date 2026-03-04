#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    map<int, set<string>> groups;
    for (int i = 0; i < n; i++) {
        string name;
        int grade;
        cin >> name >> grade;
        groups[grade].insert(name);
    }

    for (auto& [grade, names] : groups) {
        cout << grade << ":\n";
        for (auto& name : names) {
            cout << name << "\n";
        }
    }

    return 0;
}
