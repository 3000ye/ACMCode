#include "bits/stdc++.h"
#include <vector>
using namespace std;
#define ll long long
#define ld long double

void coutls(vector<int> ls) {
    for (auto i : ls) cout << i << " ";
    cout << endl;
}

void solve() {
    int n, x, y; cin >> n >> x >> y;
    vector<int> ls(n + 10);

    for (int i = y; i <= x; i ++) ls[i] = 1;
    int flag = -1;
    for (int i = y - 1; i >= 1; i --) { ls[i] = flag; flag = -flag; }
    flag = -1;
    for (int i = x + 1; i <= n; i ++) { ls[i] = flag; flag = -flag; }

    for (int i = 1; i <= n; i ++) cout << ls[i] << " ";
    cout << endl;
}

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}