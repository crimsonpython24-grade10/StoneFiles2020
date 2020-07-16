// https://codeforces.com/contest/580/submission/86637473

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef const int ci;

#define fori(i, x, y) for (int i=x; i<y; ++i)
#define forj(i, x, y) for (int i=x; i>y; --i)
#define allof(s) (s).begin(), (s).end()
 
template <class T> void minify(T & a, const T & b) { if (a > b) a = b; }
template <class T> void maxify(T & a, const T & b) { if (a < b) a = b; }

void init() {
	ios::sync_with_stdio(false);
	cin.tie(0);
}

// Code here

ci N = 100001;
int n, m, x, y, ans, tmp;
vector<int> graph[N];
int a[N], vis[N];

int dfs(int f, int cnt) {
	// if there are too many cats to handle, break
	// then loop through all the children
	//     if the point hasn't been visited, then go down to children
	//         add to current count or reset depending on bool
	//     if all points has been visited, it means there are no children *add*
	vis[f] = 1;
	if (cnt > m)
		return 0;
	bool used = false;
	fori(i, 0, graph[f].size()) {
		tmp = graph[f][i];
		if (vis[tmp] != 1) {
			used = true;
			if (a[tmp] == 1)
				dfs(tmp, cnt+a[tmp]);
			else
				dfs(tmp, 0);
		}
	}
	if (used == false)
		++ans;
}

void solve() {
	cin >> n >> m;
	fori(i, 0, n)
		cin >> a[i+1];
	memset(vis, 0, sizeof(vis));
	fori(i, 0, n-1) {
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	ans = 0;
	dfs(1, a[1]);
	cout << ans << endl;
}

int main() {
	init();
	solve();
	return 0;
}

