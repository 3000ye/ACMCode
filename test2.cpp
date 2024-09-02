#include<bits/stdc++.h>
using namespace std;

const int N = 110;
int dic[N][N], f[N][N] = {-0x3f};

void solve() {
    int n, m; string x, y;
    map<string, int> path;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> x; path[x] = i;
    }
    for(int i = 1; i <= m; i++){
        cin >> x >> y;
        dic[path[x]][path[y]] = dic[path[y]][path[x]] = 1;
    }
    
    memset(f, -0x3f, sizeof(f));
    f[1][1] = 1;
    for(int i = 1; i <= n; i++)
        for(int j = i+1; j <= n; j++)
            for(int k = 1; k < j; k++)
                if(dic[j][k]){
                    f[j][i] = f[i][j] = max(f[i][j], f[i][k]+1);
                }
    
    int res = 1;
    for(int i = 1; i <= n; i++)
        if(dic[i][n]){
            res = max(res, f[i][n]);
        }
    cout << res << endl;
}

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}