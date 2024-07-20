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

    if (x < y) {
        vector<int> ls(n, -1);
        ls[x - 1] = 1; ls[y - 1] = 1;
        coutls(ls); return;
    }
    else {
        vector<int> ls(n, -1);
        for (int i = y - 1; i <= x - 1; i ++) ls[i] = 1;
        coutls(ls); return;
    }
}

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}