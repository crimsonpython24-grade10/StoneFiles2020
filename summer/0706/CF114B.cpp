#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
using namespace std;
 
#define fori(i, s, e) for(int i = s; i < ((int)e); ++i)
#define forj(i, s, e) for(int i = s; i > ((int)e); --i)
#define ll long long
#define ci const int
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





int main() {
	init();
	solve();
	return 0;
}
