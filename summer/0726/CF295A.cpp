// 295A - Greg and Array
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef const int ci;
typedef vector<int> vi;

#define fori(i, s, e) for(int i = s; i < ((int)e); ++i)
#define forj(i, s, e) for(int i = s; i > ((int)e); --i)
#define all(s) (s).begin(), (s).end()
#define sz(s) ((int)s.size())

template <class T> void minify(T & a, const T & b) {if (a > b) a = b;}
template <class T> void maxify(T & a, const T & b) {if (a < b) a = b;}

void init() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

// Code...

ci N = 100008;
ll a[N], totalDelta, dd[N];
int n, nOps, nMetaops, opc[N], lo, hi;

struct Op {
    int lo;
    int hi;
    int delta;
} ops[N];

void solve() {
    cin >> n >> nOps >> nMetaops;
	fori (i, 0, n)
        cin >> a[i]; 
	fori (i, 0, nOps) {
		cin >> ops[i].lo >> ops[i].hi >> ops[i].delta;
		--ops[i].lo;
	}
 
	fori (i, 0, nMetaops) {
		cin >> lo >> hi;
		--lo;
		++opc[lo];
		--opc[hi];
	}
 
	fori (i, 1, nOps + 1) 
		opc[i] += opc[i-1];

	assert(opc[nOps] == 0);
 
	fori (i, 0, nOps) {
		dd[ops[i].lo] += ((ll)opc[i]) * ops[i].delta;
		dd[ops[i].hi] -= ((ll)opc[i]) * ops[i].delta;
	}
 
    totalDelta = 0;
	fori (i, 0, n) {
		totalDelta += dd[i];
		a[i] += totalDelta;
		if (i) 
            cout << ' ';
		cout << a[i];
	}

	assert(totalDelta + dd[n] == 0);
	cout << endl;
}

int main() {
    init();
    solve();
    return 0;
}
