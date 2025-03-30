class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        // code here
        deque<int> dq;
        vector<int> ans;
        int n = arr.size();
        for(int i = 0; i<n; i++){
            //remove all the lower elements pushed before
            while(!dq.empty() && arr[dq.back()] <= arr[i])
                dq.pop_back();
            dq.push_back(i);
            // resize the deque
            while(!dq.empty() && i - dq.front() >= k)
                dq.pop_front();
            //add current min
            if(i >= k - 1)
                ans.push_back(arr[dq.front()]);
        }
        return ans;
    }
};