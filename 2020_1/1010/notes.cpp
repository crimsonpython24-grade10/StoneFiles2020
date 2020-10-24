#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    int a, b, c, d;
    bool flag = false;
    for (int i=0; i<=n-1; ++i) {
        cin >> a >> b >> c >> d;
        if (b == c)
            flag = true;
    }
    if (m % 2 == 1) {
        cout << "NO" << endl;
        return;
    }
    if (flag)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
