# 算法学习与做题记录

## 打题模板

```cpp
#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define ld long double

void solve() {

}

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
```

## 栈与队列

### 单调栈与单调队列

单调栈：

```
insert x
while !sta.empty() && sta.top() < x
    sta.pop()
sta.push(x)
```

```cpp
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> dic;
        for (int i = 0, l = nums1.size(); i < l; i ++) {
            dic[nums1[i]] = i;
        }

        vector<int> res(nums1.size(), -1);
        stack<int> stk;

        for (int i = nums2.size() - 1; i >= 0; i --) {
            int cur = nums2[i];

            while (!stk.empty() and cur >= stk.top()) stk.pop();
            if (!stk.empty() and dic.count(cur)) res[dic[cur]] = stk.top();

            stk.push(cur);
        }

        return res;
    }
};
```

## BFS

```cpp
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
```

## 动态规划

```cpp
#include <bits/stdc++.h>
#include <climits>
#include <vector>
using namespace std;

/*
 * @lc app=leetcode.cn id=309 lang=cpp
 *
 * [309] 买卖股票的最佳时机含冷冻期
 */

// @castor solve=start
// 动态规划：每天都可以买也可以卖，设当前为 d 天，当前股票价格为 p
// 买入：由于冷冻期，则只能从 sale(d - 2) 递推得到，
// 而又因为不能操作，所以 sale(d - 2) = sale(d - 1)，即 buy(d) = max{ buy(d - 1), sale(d - 1) - p }
// 卖出：sale(d) = max{ sale(d - 1), buy(d - 1) + p }
// @castor solve=end

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sale = 0, buy = INT_MIN, pre_sale = 0;

        for (int p : prices) {
            // 卖出股票 p
            int new_sale = max(sale, buy + p);
            // 买入股票 p，因为有冷冻期，买入的前 1 天不能操作
            // pre_sale 为前 1 天的 sale（实际和前 2 天的 sale 一致）
            buy = max(buy, pre_sale - p);
            // 向前递推
            pre_sale = sale; sale = new_sale;
        }

        return sale;
    }
};
// @lc code=end
```