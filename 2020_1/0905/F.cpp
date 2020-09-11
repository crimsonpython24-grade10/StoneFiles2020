#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int arr[n];
    for (int i=0; i<n; ++i)
        cin >> arr[i];
    int lowest = arr[0] + arr[1];
    for (int i=2; i<n; ++i) {
        if (arr[i] >= lowest) {
            cout << "1 2 " << i+1 << endl;
            return;
        }
    }
    cout << -1 << endl;
}

int main() {
    int t;
    cin >> t;
    for (int i=0; i<t; ++i)
        solve();
    return 0;
}
