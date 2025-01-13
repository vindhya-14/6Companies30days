#include <iostream>
#include <vector>

int subset_maximization(const std::vector<int>& A, int N) {
    int odd_count = 0, even_count = 0;
    for (int i = 0; i < N; ++i) {
        if (A[i] % 2 == 0) {
            even_count++;
        } else {
            odd_count++;
        }
    }
    return std::min(odd_count, even_count);
}

int main() {
    int N;
    std::cin >> N;
    std::vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i];
    }
    int result = subset_maximization(A, N);
    std::cout << result << std::endl;
    return 0;
}
