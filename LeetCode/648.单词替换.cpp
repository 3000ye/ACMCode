#include <bits/stdc++.h>
#include <sstream>
#include <vector>
using namespace std;

/*
 * @lc app=leetcode.cn id=648 lang=cpp
 *
 * [648] 单词替换
 */

// @lc code=start
class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        sort(dictionary.begin(), dictionary.end(), [](string a, string b){return a.size() < b.size();});
        auto ls = split(sentence);

        vector<string> res;
        for (auto s : ls) {
            bool flag = false;

            for (auto d : dictionary) {
                int l = d.size();
                auto temp = s.substr(0, l);

                if (d == temp) { res.push_back(d); flag = true; break; }
            }

            if (!flag) res.push_back(s);
        }

        return join(res);
    }

    string join(vector<string> ls) {
        ostringstream oss;
        for (int i = 0; i < ls.size(); i ++) {
            if (i != 0) oss << " ";

            oss << ls[i];
        }

        return oss.str();
    }

    vector<string> split(string sentence) {
        vector<string> ls;
        istringstream iss(sentence); string s;

        while (iss >> s) ls.push_back(s);
        return ls;
    }
};
// @lc code=end

