// 1198B - Welfare State
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

ci N = 200008;
int n, nOperations, mid, val, type, person, value;
int segtree[4*N];

int get(int ix, int lo, int hi, int target) {
    assert(lo <= target && target < hi);

    if (hi - lo == 1)
        return segtree[ix];
    else {
        mid = (lo + hi) / 2;
        if (target < mid)
            return max(segtree[ix], get(2*ix, lo, mid, target));
        else
            return max(segtree[ix], get(2*ix+1, mid, hi, target));
    }
}

int get1(int target) {
    return get(1, 1, n+1, target);
}

void max1(int value) {
    maxify(segtree[1], value);
}

void alt(int ix, int lo, int hi, int target, int value) {
    assert(lo <= target && target < hi);
    if (hi - lo == 1)
        segtree[ix] = value;
    else {
        maxify(segtree[2*ix], segtree[ix]);
        maxify(segtree[2*ix+1], segtree[ix]);
        segtree[ix] = 0;

        mid = (lo + hi) / 2;
        if (target < mid) 
            alt(2*ix, lo, mid, target, value);
        else
            alt(2*ix+1, mid, hi, target, value);
    }
}

// using 1-indexing for tree leaves
void alt1(int target, int value) {
    alt(1, 1, n+1, target, value);
}

void solve() {
    cin >> n;
    fori(i, 1, n+1) {
        cin >> val;
        alt1(i, val);
    }

    cin >> nOperations;
    fori(i, 0, nOperations) {
        cin >> type;
        switch(type) {
            case 1:
                cin >> person >> value;
                alt1(person, value);
                break;
            case 2:
                cin >> value;
                max1(value);
                break;
            default:
                throw logic_error("bad");
        }
    }
    fori(i, 1, n+1) {
        if (i > 1)
            cout << ' ';
        cout << get1(i);
    }
    cout << endl;
}

int main() {
    init();
    solve();
    return 0;
}
