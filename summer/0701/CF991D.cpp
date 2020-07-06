#include <iostream>
using namespace std;

#define ll long long

string s[2];
int dp[105];
int ans;

void solve() {
	cin >> s[0] >> s[1];
	ans = 0;
	for (int i=0; i<s[1].length(); ++i) {
		if (s[0][i] == '0' && s[1][i] == '0')
			dp[i] = 2;
		else if (!(s[0][i] == 'X' && s[1][i] == 'X'))
			dp[i] = 1;
	}
	for (int i=0; i<s[1].length(); ++i) {
		if (dp[i] == 2) {
			if (dp[i+1] == 2) {
				++ans;
				if (dp[i+2] == 2) {
					++ans;
					++i;
				}
				++i;
			}
			else if (dp[i+1] == 1) {
				++ans;
				++i;
			}
		}
		else if (dp[i] == 1) {
			if (dp[i+1] == 2) {
				++ans;
				++i;
			}
		}
	}
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	return 0;
}

