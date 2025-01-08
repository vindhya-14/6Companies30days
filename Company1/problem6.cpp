#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isStrictlyIncreasing(vector<int> arr) {
        int n = arr.size();
        for (int i = 1; i < n; i++) {
            if (arr[i] <= arr[i - 1]) {
                return false;
            }
        }
        return true;
    }

    int incremovableSubarrayCount(vector<int>& nums) {
        int n = nums.size();
        int count = 0;

        for (int start = 0; start < n; start++) {
            for (int end = start; end < n; end++) {
                vector<int> ans;
                for (int i = 0; i < n; i++) {
                    if (i < start || i > end) {
                        ans.push_back(nums[i]);
                    }
                }

                if (isStrictlyIncreasing(ans)) {
                    count++;
                }
            }
        }

        return count;
    }
};

int main() {
    Solution sol;
    vector<int> nums;

    int n;
    cout << "Enter number of elements in array: ";
    cin >> n;
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        nums.push_back(x);
    }

    int result = sol.incremovableSubarrayCount(nums);
    cout << "Total incremovable subarrays: " << result << endl;

    return 0;
}
