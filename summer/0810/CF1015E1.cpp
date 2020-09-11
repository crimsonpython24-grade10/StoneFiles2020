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
void python() {ios::sync_with_stdio(false); cin.tie(0);}

// Code...

int nRows, nCols, starSize[1008][1008];
char grid[1008][1008];

int hasStar(int row, int col) {
    return 0 <= row && row < nRows && 0 <= col && col <= nCols && grid[row][col] == '*';
}

int computeStarSize(int row, int col) {
    if (grid[row][col] == '.')
        return 0;

    int size = 0;
    while (true) {
        int d = size + 1;
        if (
                hasStar(row - d, col) &&
                hasStar(row + d, col) &&
                hasStar(row, col - d) &&
                hasStar(row, col + d)) {
            size = d;
        } else
            return size;
    }
}

bool ok() {
    fori(i, 0, nRows) {
        fori(j, 0, nCols) {
           if (grid[i][j] != '.')
               return false;
        }
    }
    return true;
}

void solve() {
    cin >> nRows >> nCols;
    fori(i, 0, nRows)
        cin >> grid[i];

    int starCount = 0;
    fori(i, 0, nRows) {
        fori(j, 0, nCols) {
            starSize[i][j] = computeStarSize(i, j);
            if (starSize[i][j])
                ++starCount;
        }
    }

    fori(i, 0, nRows) {
        fori(j, 0, nCols) {
            if (starSize[i][j]) {
                fori(d, 0, starSize[i][j] + 1) {
                    grid[i-d][j] = '.';
                    grid[i+d][j] = '.';
                    grid[i][j-d] = '.';
                    grid[i][j+d] = '.';
                }
            }
        }
    }
    
    if (ok()) {
        cout << starCount << endl;
        fori(i, 0, nRows) {
            fori(j, 0, nCols) {
                if (starSize[i][j])
                    cout << (i + 1) << " " << (j + 1) << " " << starSize[i][j] << endl;
            }
        }
    } else
        cout << -1 << endl;
    
}

int main() {
    python();
    solve();
    return 0;
}
