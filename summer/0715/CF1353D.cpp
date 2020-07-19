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

int n, tcn, half;
int a[200008];

typedef struct Segment {
	int lo;
	int hi;
	bool operator < (const Segment & other) const {
		if (hi - lo != other.hi - other.lo) {
			return hi - lo < other.hi - other.lo;
		}
		return lo > other.lo;
	}
} Segment;

priority_queue<Segment> zeros;

void solve() {
	cin >> n;

	zeros.push(Segment {.lo = 0, .hi = n});

	fori(i, 1, n+1) {
		// longest of the leftmost
		Segment s = zeros.top();
		zeros.pop();
		half = s.lo + (s.hi - s.lo - 1) / 2;
		
		// remove [half, half + 1)
		a[half] = i;
		if (s.lo < half)
			zeros.push(Segment{.lo = s.lo, .hi = half});
		if (half + 1 < s.hi)
			zeros.push(Segment{.lo = half + 1, .hi = s.hi});
	}

	assert(zeros.empty());

	fori (i, 0, n) {
		if (i)
			cout << " ";
		cout << a[i];
	}
	cout << endl;

}

int main() {
	init();
	cin >> tcn;
	fori (i, 0, tcn)
		solve();
	return 0;
}
