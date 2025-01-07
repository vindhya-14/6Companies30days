#include <iostream>
#include <unordered_set>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<string> seen, res;
        
        for (int l = 0; l <= s.length() - 10; ++l) {
            string curr = s.substr(l, 10);
            
            if (seen.count(curr)) {
                res.insert(curr);
            }
            
            seen.insert(curr);
        }
        
        return vector<string>(res.begin(), res.end());
    }
};

int main() {
    Solution solution;
    string s;
    cin>>s;
    
    vector<string> result = solution.findRepeatedDnaSequences(s);
    
    for (const string& seq : result) {
        cout << seq << endl;
    }
    
    return 0;
}
