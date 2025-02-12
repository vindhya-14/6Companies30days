class Solution {
public:
    int  func(vector<int> &arr,int k)
    {
       if(k<0) return 0;
        int i=0,j=0,s=0,ans =0;

        while(j<arr.size())
        {
            s += arr[j]%2;

            while(s > k)
            {
                s -= arr[i]%2;
                i++;
            }

            ans += (j-i+1);
            j++;

        }

        return ans;

    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return func(nums,k) - func(nums,k-1);
    }
};