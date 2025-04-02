class Solution {
public:
    int f(int curr,int prev,vector<vector<int>>& envelopes){
        if(curr==envelopes.size()){
            return 0;
        }
        int notTake=0+f(curr+1,prev,envelopes);
        int take=-1e9;
        if(prev==-1 or (envelopes[prev][0]<envelopes[curr][0] and envelopes[prev][1]     <envelopes[curr][1])){
                take=1+f(curr+1,curr,envelopes);
        }
        return max(take,notTake);
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end());
        return f(0,-1,envelopes);
    }
};