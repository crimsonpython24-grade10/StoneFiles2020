// 0919A. Sport Mafia
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef const int ci;
typedef vector<int> vi;
typedef pair<ll, ll> pll;

#define INF (2e12)
#define fori(i, s, e) for(int i = s; i < ((int)e); ++i)
#define forj(i, s, e) for(int i = s; i >= ((int)e); --i)
#define all(s) (s).begin(), (s).end()
#define sz(s) ((int)s.size())

template <class T> void minify(T &a, const T &b) {if(a > b) a = b;}
template <class T> void maxify(T &a, const T &b) {if(a < b) a = b;}
void python() {ios_base::sync_with_stdio(false); cin.tie(0);}

// Code...

int findsum(int n) {
    return (1 + n) * n / 2;
}

void solve() {
    int n, k;
    cin >> n >> k;

    int steps = 1, sum = 0;

    while (true) {
        sum += steps;
        if (n - steps == sum - k) {
            cout << sum-k << endl;
            return;
        }
        ++steps;
    }
}

int main() {
    python();
    solve();
    return 0;
}
