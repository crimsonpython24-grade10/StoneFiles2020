#include <iostream>
using namespace std;

#define ll long long

const ll mod = 998244353;
int N, S, A[3001];
ll dp[3001][3001][3];

void solve() {
	cin >> N >> S;
	for (int i=0; i<N; ++i)
		cin >> A[i+1];
	dp[0][0][0] = 1;
	for (int i=1; i<=N; ++i) {
		for (int j=0; j<=S; ++j) {
			dp[i][j][0] += (dp[i-1][j][0] + (j >= A[i] ?  dp[i-1][j-A[i]][0] : 0));
			dp[i][j][1] += (dp[i-1][j][1] + (j >= A[i] ?  dp[i-1][j-A[i]][1] : 0));
			if (j == 0)
				dp[i][j][1] += dp[i-1][j][0];
			if (j == A[i])
				++dp[i][j][1];	
			dp[i][j][0] %= mod;
			dp[i][j][1] %= mod;
			dp[i][j][2] = (dp[i][j][1] + dp[i-1][j][2])%mod;
		}
	}
	cout << dp[N][S][2] << endl;
}


int main() {
	ios::sync_with_stdio(false);
	solve();
	return 0;
}
