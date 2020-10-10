// Floor Number
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

template <class T> void minify(T &a, const T &b) {if(a > b) a = b;}
template <class T> void maxify(T &a, const T &b) {if(a < b) a = b;}
void python() {ios_base::sync_with_stdio(false); cin.tie(0);}

// Code...

void solve() {
    ll n, x;
    cin >> n >> x;
    if (n == 1 || n == 2)
        cout << 1 << endl;
    else {
        fori(i, 0, 3000) {
            if (n >= ((i*x) + 3) && n <= (((i+1) * x) + 2))
                cout << i + 2 << endl;
        }
    }
    return;
}

int main() {
    python();
    ll t;
    cin >> t;
    fori (i, 0, t)
        solve();
    return 0;
}
