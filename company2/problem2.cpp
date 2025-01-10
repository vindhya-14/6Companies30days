#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string result = "";

        while (columnNumber > 0) {
            columnNumber--; 
            int remainder = columnNumber % 26;
            result += ('A' + remainder);
            columnNumber /= 26;
        }

        reverse(result.begin(), result.end());
        return result;
    }
};

int main() {
    Solution solution;
    int columnNumber;

    cout << "Enter the column number: ";
    cin >> columnNumber;

    string columnTitle = solution.convertToTitle(columnNumber);

    cout << "The corresponding column title is: " << columnTitle << endl;

    return 0;
}
