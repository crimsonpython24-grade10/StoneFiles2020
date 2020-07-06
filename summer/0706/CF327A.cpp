#include <iostream>
using namespace std;
 
#define fori(i,s,e) for(int i = s; i < ((int)e); i++)
#define ll long long
#define MOD (ll)(1e9+7)
#define INF (2e9)

template <class T> void minify(T & a, const T & b) { if (a > b) a = b; }
template <class T> void maxify(T & a, const T & b) { if (a < b) a = b; }

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
ll fpow(ll b,ll p){
	b %= MOD;
	ll ans = 1;
	while (p > 0) {
		if(p & 1) ans = (ans * b) % MOD;
		p /= 2;
		b = (b * b) % MOD;
	}
	return ans;
}

const int N = 108;
int n, ans, s;
int a[N];

void solve() {
	cin >> n;
	fori(i, 0, n)
		cin >> a[i];
	ans = -1;
	fori(i, 0, n) {
		fori(j, i+1, n+1) {
			fori(k, i, j)
				a[k] = !a[k];
			s = 0;
			fori(k, 0, n)
				s += a[k];
			maxify(ans, s);
			fori(k, i, j)
				a[k] = !a[k];
		}
	}
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	return 0;
}
