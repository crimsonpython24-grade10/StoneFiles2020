#include <iostream>
#include <algorithm>

#define ll long long

using namespace std;

const int N = 500001;
const int K = 5001;
const int INF = 1000000001;

int a[N];
int n, k;
int dp[3][K];

void solve() {
	cin >> k >> n;
	for (int i=0; i<n; ++i)
		cin >> a[i];
	sort(a, a+n);
	
	// dp[i%3][j]: j meetings in i gaps
	for (int i=0; i<=1; ++i)
		for (int j=1; j<=k; ++j)
			dp[i][j] = INF;
	dp[0][0] = 0;
	dp[1][0] = 0;
	dp[1][1] = a[1] - a[0];

	for (int i=2; i<n; ++i) {
		// current gap: a[i] - a[i-1]
		for (int j=0; j<=k; ++j) {
			dp[i%3][j] = dp[(i-1)%3][j];
			if (j) {
				dp[i%3][j] = min(
						dp[i%3][j],
						dp[(i-2)%3][j-1] + a[i] - a[i-1]
						);
			}
		}
	}

	cout << dp[(n-1)%3][k] << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	return 0;
}
