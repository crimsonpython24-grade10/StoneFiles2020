#include <bits/stdc++.h> // Globalman
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

// Variables

// Methods

void solve() {
	
}

int main() {
	init();
	solve();
	return 0;
}
