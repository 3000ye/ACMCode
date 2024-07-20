#include "bits/stdc++.h"
#include <utility>
#include <vector>
using namespace std;
#define ll long long
#define ld long double

void solve() {
    int n; cin >> n;
    map<int, int> dic;
    for (int i = 0; i < n; i ++) {
        int x; cin >> x; dic[x] ++;
    }

    vector<pair<int, int>> ls(dic.begin(), dic.end());
    sort(ls.begin(), ls.end(), [](pair<int, int> a, pair<int, int> b) {return a.first > b.first;});

    for (auto i : ls) {
        if (i.second & 1) { cout << "YES" << endl; return; }
    }

    cout << "NO" << endl;
}

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}