#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=218 lang=cpp
 *
 * [218] 天际线问题
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings)
    {
        vector<pair<int,long>> sortedBuildings;
        for(auto & building: buildings)
        {
            int left = building[0];
            int right = building[1];
            long height = building[2];
            sortedBuildings.push_back(make_pair(left,-height));
            sortedBuildings.push_back(make_pair(right,height));
        }

        std::sort(sortedBuildings.begin(),sortedBuildings.end(),[](auto &left,auto &right){return left.first < right.first || (left.first == right.first && left.second < right.second);});
       
        multiset<int,greater<int>> pq;//降序排序
        pq.insert(0);
        vector<vector<int>> ans;
        for(auto & build: sortedBuildings)
        {
            int x = build.first;
            long y = build.second;
            int top = *(pq.begin());//取第一个元素，即最大元素
            if(y < 0)//左边界
            {
                y = -y;
                if(y > top)
                {
                    ans.push_back({x,(int)y});
                }
                pq.insert(y);
            }
            else //右边界
            {
                pq.erase(pq.find(y));//只删除重复元素中的一个
                int tmp = *(pq.begin());
                if(top > tmp)
                {
                    ans.push_back({x,tmp});
                }
            }
        }
        return ans;
    }
};
// @lc code=end

