#include "bits/stdc++.h"
#include <unordered_map>
#include <vector>
using namespace std;
#define ll long long
#define ld long double

const int N = 20;
int dic[N][N], n;
vector<int> ls; unordered_map<int, int> mp;

void bfs(int x, int y, int cnt) {
    cnt += dic[x][y];
    if (x == n and y == 1) {
        ls.push_back(cnt); mp[cnt] ++; return;
    }
    else if (x == n and y != 1) {
        bfs(x, y - 1, cnt);
    }
    else if (x != n and y == 1) {
        bfs(x + 1, y, cnt);
    }
    else {
        bfs(x, y - 1, cnt);
        bfs(x + 1, y, cnt);
    }
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= n; j ++) {
            cin >> dic[i][j];
        }
    }

    bfs(1, n, 0);
    sort(ls.begin(), ls.end());
    cout << mp[ls.back()] << " " << ls.back() << endl;
}

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}