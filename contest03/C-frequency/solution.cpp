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

        int freq[26] = {};
        for (char c : s) {
            freq[c - 'a']++;
        }

        int maxFreq = *max_element(freq, freq + 26);

        string result = "";
        for (int i = 0; i < 26; i++) {
            if (freq[i] == maxFreq) {
                result += (char)('a' + i);
            }
        }

        cout << result << "\n" << maxFreq << "\n";
    }

    return 0;
}
