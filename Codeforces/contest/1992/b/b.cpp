#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define ld long double

void solve() {
    int n, k; cin >> n >> k;
    vector<int> ls(k, 0);
    for (auto &x : ls) cin >> x;

    sort(ls.begin(), ls.end());

    int cnt = 0, big = ls[k - 1];
    for (auto i : ls) {
        while (big < n and i > 0) {
            if (i == 1) cnt ++;
            else cnt += 2;

            i --; big ++;
        }

        if (big == n) break;
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