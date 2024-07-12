#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define ld long double


// @castor solve=start
// 结论题：递减输出 n ~ m + 1，然后再输出 1 ~ m
// @castor solve=end
void solve() {
    int n, m, k; cin >> n >> m >> k;

    for (int i = n; i > m; i --) cout << i << " ";
    for (int i = 1; i <= m; i ++) cout << i << " ";
    cout << endl;
}

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}