#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    int getMaxGap(vector<int>& bars) {
        sort(bars.begin(), bars.end());
        int count = 2, res = 2;
        for (int i = 1; i < bars.size(); ++i) {
            count = (bars[i - 1] + 1 == bars[i]) ? count + 1 : 2;
            res = max(res, count);
        }
        return res;
    }

    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        int hGap = getMaxGap(hBars);
        int vGap = getMaxGap(vBars);
        return min(hGap, vGap) * min(hGap, vGap);
    }
};

int main() {
    Solution solution;
    int n = 8, m = 8;
    vector<int> hBars = {1, 4, 6, 7};
    vector<int> vBars = {2, 3, 5};
    int maxArea = solution.maximizeSquareHoleArea(n, m, hBars, vBars);
    cout << "Maximum Square Hole Area: " << maxArea << endl;
    return 0;
}
