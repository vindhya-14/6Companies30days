#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        
        int child = 0;
        int cookie = 0;

        while (child < g.size() && cookie < s.size()) {
            if (s[cookie] >= g[child]) {
                child++;
            }
            cookie++;
        }

        return child;
    }
};

int main() {
    Solution solution;
    vector<int> g = {1, 2, 3};
    vector<int> s = {1, 1};

    int result = solution.findContentChildren(g, s);
    cout << result << endl;

    return 0;
}
