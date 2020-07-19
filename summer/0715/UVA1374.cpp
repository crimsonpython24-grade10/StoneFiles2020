#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef const int ci;
typedef vector<int> vi;

#define MOD (ll)(1e9+7)
#define INF (2e9)
#define fori(i,s,e) for(int i = s; i < ((int)e); i++)
#define allof(s) (s).begin(), (s).end() 
#define sz(x) ((int)x.size())

template <class T> void minify(T & a, const T & b) { if (a > b) a = b; }
template <class T> void maxify(T & a, const T & b) { if (a < b) a = b; }

void init() {
	ios::sync_with_stdio(false);
	cin.tie(0);
}

// Code here ...

ci MAX = 3000;
bool seen[MAX], skipped[MAX];
vi stacked;

// how many more operations we have
bool dfs (int depth, int target) {
	// fprintf(stderr, "[...%d: %d]\n", depth, stacked.back());
	if (depth == 1) {
		// we must use the most recent number as otherwise there's no point
		// for (int s : stacked) fprintf(stderr, "[%d]", s);

		int recent = stacked.back();
		if (recent + target < MAX && seen[recent + target])
			return true;
		if (target - recent > 0 && seen[target - recent])
			return true;
		return false;
	}

	if ((*max_element(allof(stacked)) << depth) < target)
		return false;

	set<int> candidates;
	set<int> useless;

	for (size_t i = 0; i < stacked.size(); ++i) {
		for (size_t j = i; j < stacked.size(); ++j) {
			for (int sign = 1; sign >= -1; sign -= 2) {
				int combination = stacked[i] + sign * stacked[j];
				if (combination == 0 || combination >= target * 2)
					continue;
				if (combination < 0)
					combination = -combination;

				if (seen[combination] || skipped[combination])
					continue;

				if (j != stacked.size() - 1 && combination < stacked.back()) 
					useless.insert(combination);
				else
					candidates.insert(combination);
			}
		}
	}

	for (ci &bad : useless)
		candidates.erase(bad);

	for (ci &cand : candidates) {
		stacked.push_back(cand);
		seen[cand] = true;
		if (dfs(depth - 1, target)) 
			return true;
		seen[cand] = false;
		stacked.pop_back();
		skipped[cand] = true;
	}
	for (ci &cand : candidates)
		skipped[cand] = false;

	return false;
}

int solve(int target) {
	if (target == 1)
		return 0;

	stacked.clear();
	fill(seen, seen + 3000, false);
	fill(skipped, skipped + 3000, false);
	stacked.push_back(1);
	seen[1] = true;

	for (int depth = 1; ; ++depth)
		if (dfs(depth, target))
			return depth;
}

int main() {
	init();
	int x;
	while (cin >> x, x)
		solve(x);
	return 0;
}
