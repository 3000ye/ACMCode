#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> res;
        priority_queue<tuple<int, int, int>> pque;

        for (int i = 0, l = nums1.size(); i < min(l, k); i ++) pque.emplace(-nums1[i] - nums2[0], i, 0);
        while (res.size() < k and !pque.empty()) {
            auto [_, i, j] = pque.top(); pque.pop();
            res.push_back({nums1[i], nums2[j]});

            if (j + 1 < nums2.size()) pque.emplace(-nums1[i] - nums2[j + 1], i, j + 1);
        }
        
        return res;
    }
};

int main() {
    int n,m,data,k;
    vector<int> nums1,nums2;
    cin>>n;
    for(int i=0; i<n; i++)
    {

        cin>>data;

        nums1.push_back(data);

    }

    cin>>m;
    for(int i=0; i<m; i++)
    {

        cin>>data;

        nums2.push_back(data);

    }
    cin>>k;
    vector<vector<int> > res=Solution().kSmallestPairs(nums1,nums2,k);

    vector<int> ans;
    for (auto i : res) {
        ans.push_back(i[0] + i[1]);
    }

    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i ++) {
        if (i > 0) cout << " ";
        cout << ans[i];
    }
    cout << endl;

    return 0;
}