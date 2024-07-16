// @castor solve=start
// 每次循环首先判断 `n` 是否为 `1`，如果是则直接结束
// 反之则 `n -= (k - 1)`
// @castor solve=end

#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define ld long double

void solve() {
    int n, k; cin >> n >> k;

    int cnt = 0;
    while (n > 0) {
        if (n == 1) n = 0;
        else {
            n -= (k - 1); cnt ++;
        }
    }

    cout << cnt << endl;
}

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}