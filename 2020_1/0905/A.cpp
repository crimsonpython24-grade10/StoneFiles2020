#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    cout << abs(n-k) << endl;
}

int main() {
    int t;
    cin >> t;
    for (int i=0; i<t; ++i)
        solve();
    return 0;
}
