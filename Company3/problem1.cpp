#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> maxSubsequence(std::vector<int>& nums, int k) {
        int n = nums.size(), i = 0, t = k;
        std::vector<int> ans;
        
        while (t > 0) {
            ans.push_back(nums[i]);
            i++;
            t--;
        }
        
        for (int j = i; j < n; j++) {
            int mini = std::min_element(ans.begin(), ans.end()) - ans.begin();
            if (ans[mini] < nums[j]) {
                ans.erase(ans.begin() + mini);
                ans.push_back(nums[j]);
            }
        }
        return ans;
    }
};
