#include <queue>
#include <vector>
using namespace std;

class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> pq;
    int K;

public:
    KthLargest(int k, vector<int>& nums) {
        K = k;
        for (auto& ele : nums) {
            pq.push(ele);
            if (pq.size() > K) {
                pq.pop();
            }
        }
    }
    
    int add(int val) {
        pq.push(val);
        if (pq.size() > K) {
            pq.pop();
        }
        return pq.top();
    }
};

int main() {
    vector<int> nums = {4, 5, 8, 2};
    KthLargest obj(3, nums);
    obj.add(3);
    obj.add(5);
    obj.add(10);
    obj.add(9);
    obj.add(4);
    return 0;
}
