#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;

    int len [s.length()/2+1];
    for (int i=0; i<s.length()/2+1; ++i)
        len[i] = 0;

    for (int i=0; i<s.length(); ++i) {
        int cnt = 0;
        if (s[i] == '1') {
            int tmp = 1;
            while (s[i+tmp] == 1) {
                ++tmp;
            }
            cout << tmp << endl;
            len[cnt] = tmp;
            ++cnt;
            i += tmp;
        }
    }

    for (int i=0; i<s.length()/2+1; ++i) {
        cout << len[i] << " ";
    }

    cout << endl;

}

int main() {
    int t;
    cin >> t;
    for (int i=0; i<t; ++i)
        solve();
    return 0;
}
