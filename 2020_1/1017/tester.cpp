#include <bits/stdc++.h>
using namespace std;

// 0, 1, 2
// 1, 0, 0
// 0, 1, 1
// 1, 1, 1

void solve() {
    vector<int> nums;
    for (int i=0; i<3; ++i) {
        int tmp;
        cin >> tmp;
        nums.push_back(tmp);
    }
    
    sort(nums.begin(), nums.end());

    if (nums[0] <= nums[1] && nums[1] == nums[2]) {
        cout << "YES" << endl;

        if (nums[1] == nums[0])
            cout << nums[0] << " " << nums[0] << " " << nums[0] << endl;
        else {
            cout << nums[0] << " " << nums[0] << " " << nums[1] << endl;
        }
    } else {
        cout << "NO" << endl;
    }
    return;
}

int main() {
    int t;
    cin >> t;
    for (int i=0; i<t; ++i)
        solve();
    return 0;
}
