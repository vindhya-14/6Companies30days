using ll = long long;
class Solution {
public:


    vector<ll> find_lps(string& pattern){
        //longest proper prefix which is also a suffix in the patter
        int m = pattern.length(),len=0,i=1;
        vector<ll> lps(m,0);
        while(i<m){
            if(pattern[i]==pattern[len]){
                lps[i]=len+1;
                i++;len++;
            }
            else{
                if(len!=0){
                    len = lps[len-1];
                }
                else{
                    lps[i]=0;
                    i++;
                }
            }
        }
        return lps;

    }

    long long sumScores(string s) {
        int n = s.length();
        vector<ll> lps = find_lps(s);
        // for(int i=0;i<n;i++)cout<<lps[i]<<" ";
        vector<ll> dp(n,0); // dp[i] means number of substring ending at s[i] which are also prefix of s
        ll ans=0;
        for(int i=0;i<n;i++){
            dp[i] = lps[i]==0?1:dp[lps[i]-1]+1;
            ans+=dp[i];
        }
        return ans;
    }
};