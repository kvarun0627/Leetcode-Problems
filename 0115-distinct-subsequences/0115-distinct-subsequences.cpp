class Solution {
public:
    int numDistinct(string s, string t) {
        
        int n=s.size();
        int m=t.size();

        vector<vector<int>>DP(n+1,vector<int>(m+1,0));
        long long mod=1e9+7;
        for(int i=0;i<=n;i++)
        {
            DP[i][0]=1;
        }

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                DP[i][j]=(DP[i-1][j]%mod+((s[i-1]==t[j-1])?DP[i-1][j-1]:0)%mod)%mod;
            }
        }

        return DP[n][m];
    }
};