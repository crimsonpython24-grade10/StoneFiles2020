#include <iostream>
using namespace std;

#define ll long long

const int N = 108;
int t, n, it; 
int lot, hit, ltime, etime;
int times[N], los[N], his[N];

void solve() {
	cin >> n >> it;
	for (int i=0; i<n; ++i)
		cin >> times[i] >> los[i] >> his[i];
	lot = it;
	hit = it;
	ltime = 0;

	for (int i=0; i<n; ++i) {
		etime = times[i] - ltime;
		lot = max(lot-etime, los[i]);
		hit = min(hit+etime, his[i]);
		if (lot > hit) {
			cout << "NO" << endl;
			return;
		}
		ltime = times[i];
	}
	cout << "YES" << endl;
}

int main() {
	cin >> t;
	for (int i=0; i<t; ++i)
		solve();
}
