#include "bits/stdc++.h"
#include <vector>
using namespace std;
#define ll long long
#define ld long double

void solve() {
    int n, m; cin >> n >> m;
    vector<string> dic(n);
    for (auto & s : dic) cin >> s;

    for (int i = 0, l = n / m; i < l; i ++) {
        for (int j = 0; j < l; j ++) {
            cout << dic[i * m][j * m];
        }
        cout << endl;
    }
}

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}