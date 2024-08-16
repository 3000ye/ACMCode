#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define ld long double

void solve() {
    map<string, int> dic;
    dic["ccc"] = 2; dic["aaa"] = 3; dic["bbb"] = 4;

    for (auto [k, v] : dic) {
        cout << k << endl;
    }
}

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}