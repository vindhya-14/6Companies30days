class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
         int n = nums.size();
        
         int maxi = INT_MIN;
        int l = 0;

        for(int r=0;r<n;r++)
        {   mp[nums[r]]++;
            while(mp[nums[r]] > k)
            {
                mp[nums[l]]--;
                if (mp[nums[l]] == 0) {
                mp.erase(nums[l]);
                }
                l++;
            }

            maxi = max(maxi , r-l+1);
        }
        return maxi;
    }
};