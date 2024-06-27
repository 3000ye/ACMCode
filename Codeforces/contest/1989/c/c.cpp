#include "bits/stdc++.h"
#include <utility>
using namespace std;
#define ll long long
#define ld long double

void solve() {
    int n; cin >> n;
    vector<int> m_a(n), m_b(n);
    for (auto &x : m_a) { cin >> x; }
    for (auto &x : m_b) { cin >> x; }

    int cnt_a = 0, cnt_b = 0;
    int cnt_x = 0, cnt_y = 0;
    for (int i = 0; i < n; i++ ) {
        if (m_a[i] == 1) {
            if (m_b[i] == 1) cnt_x ++;
            else cnt_a ++;
        }
        else if (m_a[i] == -1) {
            if (m_b[i] == -1) cnt_y ++;
            else if (m_b[i] == 1) cnt_b ++;
        }
        else if (m_a[i] == 0) {
            if (m_b[i] == 1) cnt_b ++;
        }
    }

    while (cnt_x --) {
        if (cnt_a < cnt_b) cnt_a ++;
        else cnt_b ++;
    }
    while (cnt_y --) {
        if (cnt_a < cnt_b) cnt_b --;
        else cnt_a --;
    }

    cout << min(cnt_a, cnt_b) << endl;
}

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}