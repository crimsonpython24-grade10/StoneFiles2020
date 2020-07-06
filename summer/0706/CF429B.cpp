#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef const int ci;
typedef vector<int> vi;
 
#define MOD (ll)(1e9+7)
#define INF (2e9)
#define for0(i, x) for (ll i=0; i<((ll)x); ++i)
#define for1(i, x) for (ll i=1; i<((ll)x); ++i)
#define fori(i, x, y) for (ll i=x; i<((ll)y); ++i)
#define forj(i, x, y) for (ll i=x; i>((ll)y); --i)
#define all(s) (s).begin(), (s).end()
#define sz(s) ((int)s.size())
#define pub push_back
#define pob pop_back
#define in1(x) (cin >> (x));
#define in2(x, y) (cin >> (x) >> (y));
#define in3(x, y, z) (cin >> (x) >> (y) >> (z));
#define pr(x) (cout << x);
#define prl(x) (cout << x << endl); 
 
template <class T> void minify(T & a, const T & b) { if (a > b) a = b; }
template <class T> void maxify(T & a, const T & b) { if (a < b) a = b; }
 
ll gcd (ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm (ll a, ll b) { return a/gcd(a, b) * b; }
ll fpow(ll b, ll p) {
	b %= MOD; ll ans = 1;
	while (p > 0)
		if(p & 1) ans = (ans * b) % MOD; p /= 2; b=(b * b) % MOD;
	return ans;
}
 
void init() {
	ios::sync_with_stdio(false);
	cin.tie(0);
}
 
// End of macros, code below this section
 
ci N = 1008;
int n, m;
int a[N][N];
ll dp[4][N][N];
 
void go(int dpi, int is, int ie, int ib, int js, int je, int jb) {
	for (int i = is; i != ie; i += ib) {
		for (int j = js; j != je; j += jb) {
			ll t = 0;
			if (i != is) maxify(t, dp[dpi][i - ib][j]);
			if (j != js) maxify(t, dp[dpi][i][j - jb]);
			dp[dpi][i][j] = t + a[i][j];
		}
	}
}
 
 
void solve() {
	in2(n, m);
	for0(i, n)
		for0(j, m)
			in1(a[i][j]);
 
	go(0, 0, n, 1, 0, m, 1);
	go(1, n-1, 0, -1, 0, m, 1);
	go(2, 0, n, 1, m-1, 0, -1);
	go(3, n-1, 0, -1, m-1, 0, -1);
 
	ll best = 0;
	for1(i, n - 1) for1(j, m - 1) {
		maxify(best, dp[0][i-1][j] + dp[3][i+1][j] + dp[1][i][j-1] + dp[2][i][j+1]);
		maxify(best, dp[0][i][j-1] + dp[3][i][j+1] + dp[1][i+1][j] + dp[2][i-1][j]);
	}
	prl(best);
}
 
int main() {
	init();
	solve();
	return 0;
}
