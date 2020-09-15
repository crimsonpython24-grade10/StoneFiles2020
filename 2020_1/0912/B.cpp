// Juggling Letters
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

void solve() {
    int n;
    cin >> n;
    string tmp;
    int cnt[26] = {0};
    fori(i, 0, n) {
        cin >> tmp;
        fori (j, 0, tmp.length()) {
            ++cnt[char(tmp[j])-97];
        }
    }
    
    fori(i, 0, 26) {
        if (cnt[i] % n != 0) {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
}

int main() {
    python();
    int t;
    cin >> t;
    fori (i, 0, t)
        solve();
    return 0;
}
