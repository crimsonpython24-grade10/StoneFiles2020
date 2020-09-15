// Omkar and Infinity Clock
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
    int n, k;
    cin >> n >> k;
    int nums[n];
    fori (i, 0, n)
        cin >> nums[i];

    int max = nums[0];
    fori (i, 0, n) {
        if (nums[i] > max)
            max = nums[i];
    }

    fori(j, 0, k) {
        int tmp = max - nums[0];
        fori(i, 0, n) {
            nums[i] = max - nums[i];
            if (nums[i] > tmp)
                tmp = nums[i];
            // cout << endl << tmp << endl << endl    
        }
        max = tmp;
    }

    fori (i, 0, n)
         cout << nums[i] << " ";
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    fori (i, 0, t)
        solve();
    return 0;
}
