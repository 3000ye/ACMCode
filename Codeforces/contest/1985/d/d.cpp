#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define ld long double

void solve() {
    int n, m; cin >> n >> m;
    int x = 0, y = 0, cnt = 0;

    char c;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            cin >> c;

            if (c == '#') {
                x += i; y += j; cnt ++;
            }
        }
    }

    x = x / cnt; y = y / cnt;
    cout << x << " " << y << endl;
}

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}