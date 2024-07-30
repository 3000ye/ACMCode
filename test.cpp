#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define ld long double

void solve() {
    long long ls[4] = {2147483647,-2147483648,-1,0};

    long long sum = 0;
    for (auto i : ls) {
        sum += i;
        cout << sum <<endl;
    }
}

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}