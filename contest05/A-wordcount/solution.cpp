#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    map<string, int> freq;
    for (int i = 0; i < n; i++) {
        string w;
        cin >> w;
        freq[w]++;
    }

    for (auto& [word, cnt] : freq) {
        cout << word << " " << cnt << "\n";
    }

    return 0;
}
