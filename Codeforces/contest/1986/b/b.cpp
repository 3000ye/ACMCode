#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define ld long double

void solve() {
    int n, m; cin >> n >> m;
    ll dic[110][110] = {0};
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) { cin >> dic[i][j]; }
    }

    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            ll cur_max = max(dic[i - 1][j], max(dic[i + 1][j], max(dic[i][j - 1], dic[i][j + 1])));
            if (dic[i][j] > cur_max) dic[i][j] = cur_max;

            cout << dic[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}