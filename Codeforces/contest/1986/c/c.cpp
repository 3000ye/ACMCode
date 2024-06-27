#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define ld long double

void solve() {
    int n, m; cin >> n >> m;
    string s; cin >> s;
    vector<int> ls; vector<bool> flag(n + 10);
    for (int i = 0; i < m; i ++) {
        int x; cin >> x;
        if (flag[x]) continue;
        
        flag[x] = true;
        ls.push_back(x);
    }
    string c; cin >> c;

    sort(ls.begin(), ls.end());
    sort(c.begin(), c.end());

    for (int i = 0, l = ls.size(); i < l; i ++) {
        int idx = ls[i] - 1;
        s[idx] = c[i];
    }

    cout << s << endl;
}

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}