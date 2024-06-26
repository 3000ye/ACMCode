#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define ld long double

void solve() {
    int x1, x2, x3; cin >> x1 >> x2 >> x3;
    int x_min = min(x1, min(x2, x3));
    int x_max = max(x1, max(x2, x3));

    cout << x_max - x_min << endl;
}

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}