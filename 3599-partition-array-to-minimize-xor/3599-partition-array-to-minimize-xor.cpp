class Solution {
public:
    int minXor(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>pref(n+1,0);
        for(int i=0;i<n;i++)
        {
            pref[i+1]=nums[i]^pref[i];
        }
        vector<vector<int>>DP(n+1,vector<int>(k+1,INT_MAX));
        DP[0][0]=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<i;j++)
            {
                int prefix_xor=pref[i]^pref[j];
                for(int p=1;p<=k;p++)
                {
                    DP[i][p]=min(DP[i][p],max(DP[j][p-1],prefix_xor));
                }
            }
        }
        return DP[n][k];
    }
};