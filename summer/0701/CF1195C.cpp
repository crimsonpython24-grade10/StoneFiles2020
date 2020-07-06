#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long
 
const int N = 100008;
int n;
int a[2][N];
ll dp[2][N];

void solve() {
	cin >> n;
	for (int row=0; row<2; ++row)
		for (int i=0; i<n; ++i)
			cin >> a[row][i];
 
	// dp[r][i] =
	// chose people from first i (a[0]..a[i-1]);
	// last chosen person from row r
	dp[0][0] = 0;
	dp[1][0] = 0;
	for (int i=1; i<=n; ++i)
		for (int row=0; row<2; ++row)
			dp[row][i] = max(
					 dp[row][i-1],
					 dp[!row][i-1] + a[row][i-1]
					);
 
	cout << max(dp[0][n], dp[1][n]) << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	return 0;
}
