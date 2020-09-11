// C1. Skyscrapers (easy version)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef const int ci;
typedef vector<int> vi;

#define fori(i, s, e) for(int i = s; i < ((int)e); ++i)
#define forj(i, s, e) for(int i = s; i >= ((int)e); --i)
#define all(s) (s).begin(), (s).end()
#define sz(s) ((int)s.size())

template <class T> void minify(T & a, const T & b) {if (a > b) a = b;}
template <class T> void maxify(T & a, const T & b) {if (a < b) a = b;}

void init() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

// Code...

ci N = 1008;
int n, a[N], result[N], height, peak;
ll sum, best, cur;

// return the maximum floor
ll check(int peak) {
    result[peak] = a[peak];

    height = a[peak];
    fori(i, peak+1, n) {
        minify(height, a[i]);
        result[i] = height;
    }

    
    height = a[peak];
    forj(i, peak-1, 0) {
        minify(height, a[i]);
        result[i] = height;
    }

    sum = 0;
    fori(i, 0, n)
        sum += result[i];

    return sum;
}

void solve() {
    cin >> n;
	fori (i, 0, n) {
		cin >> a[i];
	}
 
	best = 0;
	peak = -1;
	fori (i, 0, n) {
		cur = check(i);
		if (cur > best) {
			best = cur;
			peak = i;
		}
	}
 
	check(peak);
	fori (i, 0, n) {
		if (i) cout << ' ';
		cout << result[i];
	}
}

int main() {
    init();
    solve();
    return 0;
}
