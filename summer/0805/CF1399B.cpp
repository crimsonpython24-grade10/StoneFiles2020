// 1399A - Remove Smallest
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef const int ci;
typedef vector<int> vi;
typedef pair<ll, ll> pll;

#define INF (2e12)
#define fori(i, s, e) for(int i = s; i < ((int)e); ++i)
#define forj(i, s, e) for(int i = s; i >= ((int)e); --i)
#define all(s) (s).begin(), (s).end()
#define sz(s) ((int)s.size())

template <class T> void minify(T & a, const T & b) {if (a > b) a = b;}
template <class T> void maxify(T & a, const T & b) {if (a < b) a = b;}
void python() {ios::sync_with_stdio(false); cin.tie(0);}

// Code...

void solve() {
    int n; cin >> n;
    ll a[60], b[60];
    pll end = {INF, INF};
    fori(i, 0, n) {
        cin >> a[i];
        minify(end.first, a[i]);
    }
    fori(i, 0, n) {
        cin >> b[i];
        minify(end.second, b[i]);
    }
    ll ans = 0;
    fori(i, 0, n)
        ans += max(a[i]-end.first, b[i]-end.second);
    cout << ans << endl;
}

int main() {
    python();
    int t;
    cin >> t;
    fori(i, 0, t)
        solve();
    return 0;
}
