#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> prefixCommonArray(vector<int>& A, vector<int>& B) {
    int n = A.size();
    vector<int> result;
    unordered_set<int> common_elements;

    for (int i = 0; i < n; i++) {
        if (common_elements.count(A[i]) > 0) {
            common_elements.insert(A[i]);
        }
        
        if (common_elements.count(B[i]) > 0) {
            common_elements.insert(B[i]);
        }

        result.push_back(common_elements.size());
    }
    
    return result;
}

int main() {
    vector<int> A = {1, 3, 2, 4};
    vector<int> B = {3, 1, 2, 4};
    
    vector<int> result = prefixCommonArray(A, B);

    for (int i : result) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
