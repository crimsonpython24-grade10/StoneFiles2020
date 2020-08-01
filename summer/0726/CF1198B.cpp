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
int n, arr[N], nOperations, answer[N], maxMax;

struct Operation {
    int type;
    int person;
    int value;
} operations[N];

void solve() {
    cin >> n;
    fori(i, 1, n+1)
        cin >> arr[i];
    cin >> nOperations;
    fori(i, 0, nOperations) {
        cin >> operations[i].type;
        switch(operations[i].type) {
            case 1:
                cin >> operations[i].person >> operations[i].value;
                break;
            case 2:
                cin >> operations[i].value;
                break;
            default:
                throw logic_error("bad");
        }
    }
    fill(answer, answer+N, -1);
    maxMax = 0;
    for (int i=nOperations-1; i>=0; i--) {
        switch(operations[i].type) {
            case 1:
                if (answer[operations[i].person] == -1)
                    answer[operations[i].person] = max(maxMax, operations[i].value);
                break;
            case 2:
                maxify(maxMax, operations[i].value);
                break;
            default:
                throw logic_error("bad");
        }
    }

    fori(i, 1, n+1) {
        if (answer[i] == -1)
            answer[i] = max(maxMax, arr[i]);
        if (i > 1)
            cout << ' ';
        cout << answer[i];
    }
    cout << endl;
}

int main() {
    init();
    solve();
    return 0;
}
