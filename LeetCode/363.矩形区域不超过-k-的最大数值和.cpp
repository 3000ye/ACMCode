#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=363 lang=cpp
 *
 * [363] 矩形区域不超过 K 的最大数值和
 */

// @lc code=start
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        bool flag = n > m;
        vector<int> sum((flag ? n + 1 : m + 1), 0);
        int ans = INT_MIN;
        
        for(int i = 1; i <= (flag ? m : n); i++){
            fill(sum.begin(),sum.end(),0);
            for(int j = i; j <= (flag ? m : n); j++){
                set<int> st;
                st.insert(0);
                int a = 0;
                for(int fff = 1; fff <= (flag ? n : m); fff++){
                    sum[fff] += flag ? mat[j - 1][fff - 1] : mat[fff - 1][j - 1];
                    a += sum[fff];
                    auto b = st.lower_bound(a - k);
                    if(b != st.end()){
                        int cur = a - *b;
                        ans = max(ans,cur);
                    }
                    st.insert(a);
                }
            }
        }
        return ans;
    }
};
// @lc code=end

