#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findTheDistanceValue(vector<int>& A, vector<int>& B, int d) {
        sort(begin(B), end(B));
        int ans = 0;
        for (int n : A) {
            if (upper_bound(begin(B), end(B), n + d) == lower_bound(begin(B), end(B), n - d)) {
                ++ans;
            }
        }
        return ans;
    }
};

int main() {
    Solution solution;
    
    vector<int> A = {4, 5, 8};
    vector<int> B = {10, 9, 1, 8};
    int d = 2;
    
    cout << solution.findTheDistanceValue(A, B, d) << endl;
    
    return 0;
}
