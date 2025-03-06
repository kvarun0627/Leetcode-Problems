class Solution {
public:
   int LCS_tabulation(string &a,string&b,int m,vector<vector<int>>&dp)
    {
        for(int i=0;i<=m;i++)
        {
            dp[i][0]=0;
        }
        for(int j=0;j<=m;j++)
        {
            dp[0][j] = 0;
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= m; j++) {
                if (a[i - 1] == b[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[m][m];
    }
    int longestPalindromeSubseq(string a) {
        int m = a.size();
        string b=a;
        reverse(a.begin(),a.end());
        vector<vector<int>> dp(m + 1, vector<int>(m + 1, 0));
        return LCS_tabulation(a, b, m,dp);
    }
};