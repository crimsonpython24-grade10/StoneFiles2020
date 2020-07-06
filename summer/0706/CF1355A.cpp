#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
 
#define ll long long
#define fori(i,s,e) for(ll i = s; i < ((ll)e); i++)
#define MOD (ll)(1e9+7)
#define INF (2e9)

template <class T> void minify(T & a, const T & b) { if (a > b) a = b; }
template <class T> void maxify(T & a, const T & b) { if (a < b) a = b; }

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
ll fpow(ll b, ll p) {
	b %= MOD; ll ans = 1;
	while (p > 0) {
		if (p & 1) ans = (ans * b) % MOD; 
		p /= 2; b = (b * b) % MOD;
	}
	return ans;
}

void init() {
	ios::sync_with_stdio(false);
	cin.tie(0);
}

ll delta(ll a0) {
	ll mind = 1000, maxd = -1000;
	ll a = a0;
	while (a) {
		mind = min(mind, a%10);
		maxd = max(maxd, a%10);
		a /= 10;
	}
	return mind * maxd;
}

void solve() {
	int t;
	cin >> t;
	fori(i, 0, t) {
		ll a, k;
		cin >> a >> k;

		fori(i, 0, k-1) {
			ll d = delta(a);
			if (d == 0)
				break;
			a += d;
		}
		cout << a << endl;
	}
}

int main() {
	init();
	solve();
	return 0;
}
