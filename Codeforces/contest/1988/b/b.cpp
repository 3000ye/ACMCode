// @castor solve=start
// 将连续的 `00...0` 看作 `0`，然后比较 `0` 和 `1` 的个数，`cnt1 > cnt0` 输出 `Yes`。
// @castor solve=end

#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define ld long double

void solve() {
    int n; cin >> n;
    int cnt0 = 0, cnt1 = 0;

    bool flag = false;
    for (int i = 0; i < n; i ++) {
        char x; cin >> x;

        if (x == '0' and !flag) { cnt0 ++; flag = true; }
        else if (x == '1') { cnt1 ++; flag = false; }
    }

    cout << (cnt1 > cnt0 ? "Yes" : "No") << endl;
}

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}