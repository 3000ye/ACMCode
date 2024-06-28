#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define ld long double

void solve() {
    int n; cin >> n;
    while (n -- ) {
        int x, y; cin >> x >> y;

        if (y < -1) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
}

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}