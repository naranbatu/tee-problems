#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<pair<int, int>> meetings(n);
    for (int i = 0; i < n; i++) {
        cin >> meetings[i].second >> meetings[i].first; // {end, start}
    }

    sort(meetings.begin(), meetings.end());

    int count = 0;
    int lastEnd = -1;

    for (auto& [end, start] : meetings) {
        if (start >= lastEnd) {
            count++;
            lastEnd = end;
        }
    }

    cout << count << "\n";

    return 0;
}
