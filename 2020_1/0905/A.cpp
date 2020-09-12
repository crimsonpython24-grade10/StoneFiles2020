#include <bits/stdc++.h>
using namespace std;

// init. position of A: n, abs. diff.: k

void solve() {
    int n, k;
    cin >> n >> k;
    if (k > n)
        cout << k-n << endl;
    else
        cout << (n-k)%2 << endl;
    return;
}

int main() {
    int t;
    cin >> t;
    for (int i=0; i<t; ++i)
        solve();
    return 0;
}
