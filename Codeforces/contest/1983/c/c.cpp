#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define ld long double

void solve() {
    int n; cin >> n;
    int tot = 0;

    vector<int> a(n, 0), b(n, 0), c(n, 0);
    for (auto &x : a) { cin >> x; tot += x; }
    for (auto &x : b) cin >> x;
    for (auto &x : c) cin >> x;

    int target = tot / 3 + (tot % 3 ? 1 : 0);
    // cout << "target = " << target << endl;

    int la = 0, ra = 0, lb, rb, lc, rc;
    int sum = 0, i = 0;
    bool flag = false;
    while (i < n) {
        sum += a[i];
        
        if (sum >= target) {
            ra = i; i ++; lb = i; sum = 0; flag = true;
            break;
        }
        else i ++;
    }

    if (!flag) { cout << -1 << endl; return; }
    else flag = false;
    // cout << "a ok: " << la + 1 << " " << ra + 1 << endl;

    while (i < n) {
        sum += b[i];

        if (sum >= target) {
            rb = i; i ++; lc = i; sum = 0; flag = true;
            break;
        }
        else i ++;
    }

    if (!flag) { cout << -1 << endl; return; }
    else flag = false;
    // cout << "b ok: " << lb + 1 << " " << rb + 1 << endl;


    while (i < n) {
        sum += c[i];
        if (sum >= target) flag = true;

        i ++;
    }

    if (!flag) { cout << -1 << endl; return; }
    // cout << "c ok" << endl;

    cout << la + 1 << " " << ra + 1 << " " << lb + 1 << " " << rb + 1 << " " << lc + 1 << " " << n << endl;
}

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}