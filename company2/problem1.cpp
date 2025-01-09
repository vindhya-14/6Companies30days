#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.size();
        int a[26] = {0};
        for (const char& c : s) {
            a[c - 'a']++;
        }
        for (int i = 0; i < n; i++) {
            if (a[s[i] - 'a'] == 1) {
                return i;
            }
        }
        return -1;
    }
};

int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;

    Solution solution;
    int result = solution.firstUniqChar(input);

    if (result != -1) {
        cout << "The first unique character is at index: " << result << endl;
    } else {
        cout << "No unique character found in the string." << endl;
    }

    return 0;
}
