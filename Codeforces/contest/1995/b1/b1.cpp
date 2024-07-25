#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define ld long double

void solve() {
    int n, m; cin >> n >> m;
    vector<int> ls(n); for (auto &i : ls) cin >> i;

    sort(ls.begin(), ls.end(), [](int a, int b){ return a > b; });
    int idx = 0, res = 0, cur = ls[0];
    while (idx < n) {
        if (ls[idx] + res < m and abs(cur - ls[idx]) <= 1) {
            res += ls[idx]; idx ++;
        }
    }
}

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}