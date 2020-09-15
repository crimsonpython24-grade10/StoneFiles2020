// disjoint set demonstration
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

struct DisjointSet {
    vi parent;
    vi rk;
    int n;
    DisjointSet(int n) {
        parent.resize(n);
        rk.assign(n, 0);
        iota(parent.begin(), parent.end(), 0);
    }
    int anc(int a) {
        return parent[a] = (parent[a] == a ? a : anc(parent[a]));
    }
    bool unite(int a, int b) {
        a = anc(a);
        b = anc(b);
        if (a == b)
            return false;
        if (rk[a] > rk[b]) 
            swap(a, b);
        parent[a] = b;
        rk[n] += rk[a] == rk[b];
        return true;
    }
};

void solve() {
    return;
}

int main() {
    python();
    
    const int n = 10;
    DisjointSet djs(n);
    while (true) {
        int a, b;
        cin >> a >> b;
        djs.unite(a, b);
        fori(i, 0, n) {
            cout << djs.anc(i) << " ";
            if (i == n-1)
                cout << endl;
        }
    }

    return 0;
}
