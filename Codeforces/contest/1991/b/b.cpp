#include "bits/stdc++.h"
#include <vector>
using namespace std;
#define ll long long
#define ld long double

void solve() {
    int n; cin >> n;
    vector<int> ls(n - 1); for (auto &i: ls) cin >> i;
    vector<int> res(n, 0);

    for (int i = 0; i < n - 1; i ++) {
        res[i] = ls[i];
        if (i > 0 and (res[i] & res[i - 1]) != ls[i - 1]) {
            res[i] = res[i - 1] | res[i];
        }
    }

    res[n - 1] = ls[n - 2];
    if ((res[n - 2] & res[n - 1]) != ls[n - 2]) {
        cout << "-1" << endl; return;
    }

    for (auto i : res) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}