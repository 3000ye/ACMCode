#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define ld long double

void solve() {
    string x, y; cin >> x >> y;

    swap(x[0], y[0]);
    cout << x << " " << y << endl;
}

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}