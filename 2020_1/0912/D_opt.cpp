// chocolate bunny
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
    ll k;
    cin >> n >> k;
    vi A(n);
    fori(i, 0, n)
        cin >> A[i];
    --k;
    for (int i=0, d = *max_element(A.begin(), A.end()); i<n; ++i)
        A[i] = d - A[i];
    k %= 2;
    if (k)
        for (int i=0, d=*max_element(A.begin(), A.end()); i<n; ++i)
            A[i] = d - A[i];
    fori(i, 0, n)
        cout << A[i] << " \n"[i == n-1];
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
