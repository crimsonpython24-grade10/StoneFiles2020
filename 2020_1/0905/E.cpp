#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;

    // array of consecutives, worst n/2+1
    int cons[s.length()/2+1] = {0};
    int idx = 0;
    int n = sizeof(cons)/sizeof(cons[0]);

    // calculate maximum consecs
    for (int i=0; i<s.length(); ++i) {
        if (s[i] == '1') {
            int tmp = 0;
            while (s[i] == '1') {
                ++tmp;
                ++i;
            }
            cons[idx] = tmp;
            ++idx;
        }
    }
    
    sort(cons, cons+n, greater<int>());

    int ans = 0;
    for (int i=0; i<s.length()/2+1; ++i) {
        if (i % 2 == 0) ans += cons[i];
    }

    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    for (int i=0; i<t; ++i)
        solve();
    return 0;
}
