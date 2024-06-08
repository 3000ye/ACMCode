#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define ld long double

void solve() {
    int n, m; cin >> n >> m;
    vector<int> goals(m), eat(m);
    for (auto &i : goals) cin >> i;

    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            int x; cin >> x;
            eat[j] += x;
        }
    }

    bool flag = true;
    for (int i = 0; i < m; i ++) {
        if (goals[i] > eat[i]) {
            flag = false; break;
        }
    }

    cout << (flag ? "Yes" : "No") << endl;
}

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}