#include <iostream>
#include <stack>
#include <string>
using namespace std;

string printMinNumberForPattern(string S) {
    int n = S.length();
    stack<int> st;
    string result = "";
    int num = 1;
    
    // Traverse through the string
    for (int i = 0; i <= n; i++) {
        // Push the current number to the stack
        st.push(num++);
        
        // If we've reached the end of the string or the pattern is 'I', pop from the stack
        if (i == n || S[i] == 'I') {
            while (!st.empty()) {
                result += to_string(st.top());
                st.pop();
            }
        }
    }
    
    return result;
}

int main() {
    // Test the function with a sample input
    string pattern = "IIDDD";
    cout << printMinNumberForPattern(pattern) << endl;  // Output: 126543
    return 0;
}
