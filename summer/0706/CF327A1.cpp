#include <iostream>
#include <algorithm>
#include <cmath>
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

int n, n0, n1, x, minn, best;
int arr[101];

void solve() {
	cin >> n;
	n0 = 0;
	n1 = 0;
	minn = 0;
	best = -1;
	fori(i, 0, n) {
		cin >> x;
		if (x == 0)
			++n0;
		else
			++n1;
		arr[i] = n0 - n1;
		best = max(best, arr[i] - minn);
		if (arr[i] < minn)
			minn = arr[i];
	}
	cout << n1 + best << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	return 0;
}
