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

int x, depth;
vector<int> state;

bool dfs(int depth, int target) {
	if (depth == 0)
		return state.back() == target;

	cout << depth << " " << target << endl;

	for (size_t i = 0; i < state.size(); i++) {	
		for (size_t j = i; j < state.size(); j++) {
			state.push_back(state[i] + state[j]);
			if (dfs(depth - 1, target)) return true;
			state.pop_back();

			state.push_back(abs(state[i] - state[j]));
			if (dfs(depth - 1, target)) return true;
			state.pop_back();
		}
	}
	return false;
}

void solve(int x) {
	if (x == 1) {
		cout << 0 << endl;
		return;
	}
	depth = 1;
	state.clear();
	state.push_back(1);
	while (!dfs(depth, x))
		++depth;
	cout << depth << endl;
	return;
}

int main() {
	init();
	while (cin >> x, x)
		solve(x);
	return 0;
}
