#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        unordered_set<int> vis;
        for (string s : startWords) {
            int hash = 0;
            for (int i = 0; i < s.size(); i++) {
                hash += (1 << (s[i] - 'a'));
            }
            vis.insert(hash);
        }
        
        int res = 0;
        for (string s : targetWords) {
            for (int k = 0; k < s.size(); k++) {
                int hash = 0;
                for (int i = 0; i < s.size(); i++) {
                    if (i == k) continue;
                    hash += (1 << (s[i] - 'a'));
                }
                if (vis.count(hash)) {
                    res++;
                    break;
                }
            }
        }
        
        return res;
    }
};
