#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define ld long double

void solve() {
    int n, m; cin >> n >> m;
    int dic[550][550];

    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) cin >> dic[i][j];
    }

    vector<int> row(n, 0), col(m, 0);
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            int x; cin >> x;
            dic[i][j] = (dic[i][j] + 3 - x) % x;
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