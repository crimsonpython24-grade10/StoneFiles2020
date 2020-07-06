#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ci = const int;
using vi = vector<int>;

#define fori(i, s, e) for(int i = s; i < ((int)e); ++i)
#define forj(i, s, e) for(int i = s; i > ((int)e); --i)
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

ci N = 108;
int n, m;
int deg[N];
bool exists[N];
vi graph[N];

void solve() {
	cin >> n >> m;
	fori(i, 0, m) {
		int x, y;
		cin >> x >> y;
		--x;
		--y;
		graph[x].push_back(y);
		graph[y].push_back(x);
		++deg[x];
		++deg[y];
	}

	fori(i, 0, n)
		exists[i] = true;

	int nSteps = 0;
	while (true) {
		vi toDel;
		fori(i, 0, n) {
			if (exists[i] && deg[i] == 1) {
				toDel.push_back(i);
			}
		}
		if (!toDel.size())
			break;
		for (ci &i : toDel) {
			for (ci &j : graph[i]) {
				if (exists[j]) {
					deg[j]--;
				}
			}
			deg[i] = 0;
			exists[i] = false;
		}
		++nSteps;
	}
	cout << nSteps << endl;
}


int main() {
	init();
	solve();
	return 0;
}
