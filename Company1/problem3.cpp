#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int rows = img.size();
        int cols = img[0].size();
        vector<vector<int>> result(rows, vector<int>(cols, 0));
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                result[r][c] = calculateAverage(img, r, c, rows, cols);
            }
        }
        return result;
    }

private:
    int calculateAverage(const vector<vector<int>>& img, int r, int c, int rows, int cols) {
        int total = 0;
        int count = 0;
        int top = max(0, r - 1);
        int bottom = min(rows, r + 2);
        int left = max(0, c - 1);
        int right = min(cols, c + 2);
        for (int row = top; row < bottom; row++) {
            for (int col = left; col < right; col++) {
                total += img[row][col];
                count += 1;
            }
        }
        return total / count;
    }
};

int main() {
    vector<vector<int>> img = {
        {100, 200, 100},
        {200, 50, 200},
        {100, 200, 100}
    };
    Solution solution;
    vector<vector<int>> smoothedImg = solution.imageSmoother(img);
    for (const auto& row : smoothedImg) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}
