#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define ld long double

void solve() {
    int n; cin >> n;
    int res = 0;
    for (int i = 1; i <= n; i ++) {
        int x; cin >> x;

        if (i & 1) {
            res = max(res, x);
        }
    }

    cout << res << endl;
}

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}