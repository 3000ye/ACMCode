#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define ld long double

void solve() {
    int n; cin >> n;

    int sum = 0, res = 0, x;
    while (n -- ) {
        cin >> x; sum += x;

        if ((sum / 2) == x) res ++;
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