#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

class ThroneInheritance {
public:
    unordered_map<string, vector<string>> bche;
    unordered_map<string, bool> dead;
    string king;

    ThroneInheritance(string kingName) {
        king = kingName;
    }

    void birth(string parentName, string childName) {
        bche[parentName].push_back(childName);
    }

    void death(string name) {
        dead[name] = true;
    }

    void dfs(vector<string>& ans, string papa) {
        if (!dead[papa]) ans.push_back(papa);
        for (auto bcha : bche[papa]) {
            dfs(ans, bcha);
        }
    }

    vector<string> getInheritanceOrder() {
        vector<string> ans;
        dfs(ans, king);
        return ans;
    }
};

int main() {
    ThroneInheritance ti("king");

    ti.birth("king", "prince1");
    ti.birth("king", "prince2");
    ti.birth("prince1", "child1");
    ti.birth("prince1", "child2");
    ti.birth("prince2", "child3");

    ti.death("prince1");

    vector<string> order = ti.getInheritanceOrder();

    for (string name : order) {
        cout << name << " ";
    }
    cout << endl;

    return 0;
}
