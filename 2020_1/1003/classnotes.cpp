#include <bits/stdc++.h>
using namespace std;

int main() {
    priority_queue<pair<int, int>> pq;
    pq.emplace(1, 2);
    pq.emplace(2, 3);
    pq.emplace(1, 0);
    pq.emplace(5, 8);
    pq.emplace(5, 2);
    while (not pq.empty()) {
        auto [a, b] = pq.top();
        pq.pop();
        cout << a << " " << b << "\n";
    }
}
