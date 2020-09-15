#include <iostream>
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

void solve() {
    int n; cin >> n;
    vi int A(n);
    ci M = 5;
    fori(i, 0, n)
        cin >> A[i];
    sort(A.begin(), a.end());

    int team_num = 0, max_num = 0;
    for (int i=0, j=0; i<n; i=j) {
        while (j<n and A[j]-A[i] <= M)
            ++j;
        ++team_num;
        max_num = max(max_num, j-1);
    }
    cout << max_num << endl;

}

int main() {
    python();
    solve();
    return 0;
}
