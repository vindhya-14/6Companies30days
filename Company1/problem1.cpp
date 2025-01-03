#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) {
        // Step 1: Shift the rectangle coordinates so that the circle is at (0, 0)
        x1 -= x_center;
        x2 -= x_center;
        y1 -= y_center;
        y2 -= y_center;

        // Step 2: Calculate the minimum distance to the rectangle along the x-axis
        // If the circle's center is outside the rectangle along the x-axis, choose the closest edge's square
        // Otherwise, the minimum distance along x-axis is 0
        int minX = (x1 * x2 > 0) ? min(x1 * x1, x2 * x2) : 0;

        // Step 3: Calculate the minimum distance to the rectangle along the y-axis
        // If the circle's center is outside the rectangle along the y-axis, choose the closest edge's square
        // Otherwise, the minimum distance along y-axis is 0
        int minY = (y1 * y2 > 0) ? min(y1 * y1, y2 * y2) : 0;

        // Step 4: Check if the sum of the squared distances is within the circle's radius
        // Compare minX + minY with the squared radius
        return minX + minY <= radius * radius;
    }
};

int main() {
    Solution sol;

    // Example Test Case 1
    int radius1 = 3, x_center1 = 1, y_center1 = 1;
    int x1_1 = 4, y1_1 = 4, x2_1 = 7, y2_1 = 7;
    bool result1 = sol.checkOverlap(radius1, x_center1, y_center1, x1_1, y1_1, x2_1, y2_1);
    // Output: false (Circle does not overlap with rectangle)
    cout << "Test Case 1: " << (result1 ? "true" : "false") << endl;

    // Example Test Case 2
    int radius2 = 5, x_center2 = 0, y_center2 = 0;
    int x1_2 = -4, y1_2 = -4, x2_2 = 4, y2_2 = 4;
    bool result2 = sol.checkOverlap(radius2, x_center2, y_center2, x1_2, y1_2, x2_2, y2_2);
    // Output: true (Circle overlaps with rectangle)
    cout << "Test Case 2: " << (result2 ? "true" : "false") << endl;

    return 0;
}
