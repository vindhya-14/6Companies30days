#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int median = (n % 2 == 0) ? (nums[n/2] + nums[n/2-1]) / 2 : nums[n/2];
        int steps = 0;
        for (auto it : nums) {
            steps += abs(it - median);
        }
        return steps;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    Solution sol;
    cout << sol.minMoves2(nums) << endl;
    return 0;
}
