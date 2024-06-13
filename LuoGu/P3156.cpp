#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define ld long double

void solve() {
    int n, m; cin >> n >> m;
    vector<int> in(n);
    for (auto &i : in) cin >> i;

    while (m -- ) {
        int idx; cin >> idx;

        cout << in[idx - 1] << endl;
    }
}

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}