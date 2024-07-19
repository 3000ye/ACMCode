#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=321 lang=cpp
 *
 * [321] 拼接最大数
 */

// @lc code=start
class Solution {
public:
    vector<int> func(vector<int> v, int k){
        int n = v.size();
        if (n <= k) return v;
        
        vector<int> ans; int temp = n - k;
        for (int i=0; i<n; i++){
            while(!ans.empty() and v[i]>ans.back() and temp-->0)
                ans.pop_back();

            ans.push_back(v[i]);
        }
        ans.resize(k);
        return ans;
    }

    vector<int> solve(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> res(k, 0);
        int l1 = nums1.size(), l2 = nums2.size();

        for (int s=max(0, k-l2); s<=min(k, l1); s++){
            vector<int> ttt;
            int i = 0, j = 0;
            vector<int> tp1 = func(nums1, s);
            vector<int> tp2 = func(nums2, k-s);
            auto it1 = tp1.begin(), it2 = tp2.begin();

            while (it1 != tp1.end() or it2 != tp2.end()){
                ttt.push_back(lexicographical_compare(it1, tp1.end(), it2, tp2.end()) ? *it2++ : *it1++);
            }

            res = lexicographical_compare(res.begin(), res.end(), ttt.begin(), ttt.end()) ? ttt : res;
        }
        return res;
    }
};
// @lc code=end

