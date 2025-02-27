class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(n,2));

        map<int,int>mp;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            mp[arr[i]]=i;
            for(int j=0;j<i;j++)
            {
                int prev_no=arr[i]-arr[j];
                if(prev_no<arr[j] && mp.find(prev_no)!=mp.end())
                {
                    dp[i][j]=1+dp[j][mp[prev_no]];
                    ans=max(dp[i][j],ans);
                }
            }
        }
        return ans;
    }
};