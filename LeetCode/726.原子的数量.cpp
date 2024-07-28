#include <bits/stdc++.h>
#include <string>
using namespace std;

/*
 * @lc app=leetcode.cn id=726 lang=cpp
 *
 * [726] 原子的数量
 */

// @lc code=start
class Solution {
public:
    string countOfAtoms(string formula) {
        string res = "";
        for (int i = 0, l = formula.size(); i < l; i ++) {
            if (formula[i] == ')') {
                // 找出 () 中的所有元素
                string temp = "";
                while (res[-1] != '(') { temp = res[-1] + temp; res.pop_back(); }
                res.pop_back();

                // 判断 () 后面是否有数字
                if (formula[i + 1] >= '0' and formula[i + 1] <= '9') {
                    // 计算数字（可能不止一位）
                    int t = getInt(++ i, formula);

                    // 遍历temp
                    int idx = 0, k = temp.size();
                    while (idx < k) {
                        string s = getString(idx, temp);
                        int n = getInt(idx, temp);
                        n *= k;
                        res += s;
                        res += std::to_string(n);
                    }
                }
                else res += temp;
            }
            else res += formula[i];
        }

        map<string, int> dic;
        int idx = 0, l = res.size();
        while (idx < l) {
            string temp = getString(idx, res);
            int t = getInt(idx, res);
            dic[temp] += t;
        }

        vector<pair<string, int>> ls(dic.begin(), dic.end());
        sort(ls.begin(), ls.end(), [](pair<string, int> a, pair<string, int> b){
            return a.first < b.first;
        });

        string ans = "";
        for (auto [i, j] : ls) {
            ans += i; ans += (j == 0 ? "" : std::to_string(j));
        }

        return ans;
    }

    string getString(int& idx, string str) {
        string temp = "";
        while ((str[idx] >= 'a' and str[idx] <= 'z') or (str[idx] >= 'A' and str[idx] <= 'Z')) {
            temp += str[idx]; idx ++;
        }

        return temp;
    }

    int getInt(int& idx, string str) {
        stack<int> stk;
        while (str[idx] >= '0' and str[idx] <= '9') { stk.push(str[idx] - '0'); idx ++; }
        int t = 0, e = 1;
        while (!stk.empty()) { t += stk.top() * e; e *= 10; }

        return t;
    }
};
// @lc code=end

