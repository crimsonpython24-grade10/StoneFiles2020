// Yet Anotherr Two Integers Problem
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
    int a, b;
    cin >> a >> b;
    if ((a-b)%10 == 0)
        cout << abs(a - b) / 10 << endl;
    else
        cout << abs(a-b) / 10 + 1 << endl;
}

int main() {
    python();
    int t; 
    cin >> t;
    fori (i, 0, t)
        solve();
    return 0;
}
