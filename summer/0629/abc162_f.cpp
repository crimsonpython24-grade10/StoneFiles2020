#include <iostream>
using namespace std;

#define ll long long

const ll INF = 1e18;
const int N = 200001;
int n;
long long a[N], dp[N][3];

void solve() {
	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> a[i];
	
	dp[0][0] = -INF;
	dp[0][1] = 0;
	dp[0][2] = -INF;
	dp[1][0] = a[0];
	dp[1][1] = -INF;
	dp[1][2] = 0;

	for (int i=2; i<=n; ++i) {
		for (int j=0; j<3; ++j) {
			dp[i][j] = dp[i-2][j] + a[i-1];
			if (j)
				dp[i][j] = max(dp[i][j], dp[i-1][j-1]);
		}
	}
	cout << dp[n][n % 2 == 0 ? 1 : 2] << endl;
}

int main() {
	ios::sync_with_stdio(false);
	solve();
	return 0;
}
