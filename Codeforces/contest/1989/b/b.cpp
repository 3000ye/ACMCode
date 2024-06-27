#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define ld long double

void solve() {
    string a, b; cin >> a >> b;

    int res = 999999;
    for (int i = 0, l = b.size(); i < l; i ++) {
        int idx_a = 0, idx_b = i;
        int cnt = 0;
        while (idx_a < a.size() and idx_b < l) {
            if (a[idx_a] == b[idx_b]) {
                idx_a ++; idx_b ++;
            }
            else {
                idx_a ++; cnt ++;
            }
        }

        res = min(res, cnt + (int)a.size() - idx_a);
    }

    cout << res + b.size() << endl;
}

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}