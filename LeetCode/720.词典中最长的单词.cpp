#include <bits/stdc++.h>
#include <string>
#include <unordered_map>
using namespace std;

/*
 * @lc app=leetcode.cn id=720 lang=cpp
 *
 * [720] 词典中最长的单词
 */

// @lc code=start
class Solution {
public:
    unordered_map<string, bool> dic;

    string longestWord(vector<string>& words) {
        for (auto i : words) dic[i] = true;

        sort(words.begin(), words.end(), [](string a, string b){
            if (a.size() == b.size()) return a < b;
            else return a.size() > b.size();
        });

        for (auto s : words) {
            if (check(s)) return s;
        }

        return "";
    }

    bool check(string s) {
        cout << s << endl;
        for (int i = 0, l = s.size(); i < l; i ++) {
            string temp = s.substr(0, i + 1);

            cout << temp << endl;
            if (!dic.count(temp)) return false;
        }

        return true;
    }
};
// @lc code=end

