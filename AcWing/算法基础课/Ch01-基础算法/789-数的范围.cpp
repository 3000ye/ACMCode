#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define ld long double

// const int N = 1e5 + 10;
// int ls[N];

void solve() {
    int n, q; cin >> n >> q;
    vector<int> ls(n);
    for (auto &i : ls) cin >> i;

    while (q -- ) {
        int x; cin >> x;
        int l = 0, r = n - 1;
        
        while (l < r) {
            int mid = (l + r) >> 1;

            if (ls[mid] >= x) r = mid;
            else l = mid + 1;
        }

        if (ls[l] != x) {
            cout << "-1 -1" << endl;
            continue;
        }

        cout << l << " ";

        l = 0, r = n - 1;
        while (l < r) {
            int mid = (l + r) >> 1;

            if (ls[mid] < x) l = mid + 1;
            else r = mid;
        }

        cout << r << endl;
    }
}

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}