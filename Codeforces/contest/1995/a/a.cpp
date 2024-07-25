// @castor solve=start
// 从中间开始放置，每条对角线的数量为：
// n, n - 1, n - 1, n - 2, n - 2, ..., 2, 2, 1, 1
// 直接模拟，直到全部放置完成
// @castor solve=end

#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define ld long double

void solve() {
    int n, k; cin >> n >> k;
    if (k == 0) { cout << 0 << endl; return; }
    if (n >= k) { cout << 1 << endl; return; }

    int cnt = 1; k -= n; n --;
    while (k > 0) {
        if (k > n) {cnt ++; k -= n;}
        else if (k > 0) {cnt ++; k = 0;}

        if (k > n) {cnt ++; k -= n;}
        else if (k > 0) {cnt ++; k = 0;}

        n --;
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