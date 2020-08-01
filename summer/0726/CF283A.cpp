// 283A - Cows and Sequence
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef const int ci;
typedef vector<int> vi;

#define fori(i, s, e) for(int i = s; i < ((int)e); ++i)
#define forj(i, s, e) for(int i = s; i > ((int)e); --i)
#define all(s) (s).begin(), (s).end()
#define sz(s) ((ll)s.size())

template <class T> void minify(T & a, const T & b) {if (a > b) a = b;}
template <class T> void maxify(T & a, const T & b) {if (a < b) a = b;}

void init() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

// Code...

ci N = 200008;
ll n, t, len, sum, a, x, k, arr[N];

void solve() {
    memset(arr, 0, sizeof(arr));
    cin >> n;
    len = 1;
    sum = 0;
    while(n--) {
        cin >> t;
        // just keep track of the last element
        if (t == 1) {
            // add d to first n numbers
            cin >> a >> x;
            arr[a-1] += x;
            sum += a*x;
        }
        else if (t == 2) {
            // append k to last item
            cin >> k;
            arr[len] = k;
            arr[len-1] -= k;
            ++len;
            sum += k;
        } else {
            // remove number from list
            --len;
            arr[len-1] += arr[len];
            sum -= arr[len];
            arr[len] = 0;
        }

        // screw this
        cout << fixed << setprecision(6) << (double)sum/len << endl;
    }
}

int main() {
    init();
    solve();
    return 0;
}
