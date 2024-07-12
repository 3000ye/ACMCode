#include "bits/stdc++.h"
#include <utility>
using namespace std;
#define ll long long
#define ld long double

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    for (int i = 0; i < 5; i ++) {
        if (b > c) swap(b, c);
        if (a > b) swap(a, b);
        if (a > c) swap(a, c);

        a ++;
    }

    cout << a * b * c << endl;
}

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}