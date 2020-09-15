// Remove smallest
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
    int n;
    cin >> n;
    int a[n];
    fori(i, 0, n)
        cin >> a[i];
    
    int k = sizeof(a)/sizeof(a[0]);
    sort(a, a+k, greater<int>());
    
    fori(i, 0, n-1) {
        if (a[i] - a[i+1] > 1)  {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
    return;
}

int main() {
    python();
    int t;
    cin >> t;
    fori(i, 0, t)
        solve();
    return 0;
}
