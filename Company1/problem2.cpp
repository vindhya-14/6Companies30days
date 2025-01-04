#include <iostream>
using namespace std;

class Solution {
public:
    int findTheWinner(int n, int k, int val = 0) {
        for (int i = 2; i < n + 1; i++)
            val = (val + k) % i;
        return val + 1;
    }
};

int main() {
    Solution solution;
    int n, k;

    cout << "Enter the number of friends (n): ";
    cin >> n;
    cout << "Enter the step count (k): ";
    cin >> k;

    int winner = solution.findTheWinner(n, k);
    cout << "The winner is friend number: " << winner << endl;

    return 0;
}
