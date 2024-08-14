#include "bits/stdc++.h"
#include <vector>
using namespace std;
#define ll long long
#define ld long double

void solve() {
    set<int> ls = {1, 3};
    set<int> temp = {3, 1};

    auto flag = ls == temp;
    cout << flag << endl;
}

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}