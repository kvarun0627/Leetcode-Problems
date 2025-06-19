class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string>st(wordDict.begin(),wordDict.end());
        int n=s.size();
        vector<bool>DP(n+1,false);
        DP[n]=true;
        for(int i=n-1;i>=0;i--)
        {
            string str="";
            for(int j=i;j<n;j++)
            {
                str+=s[j];
                DP[i]=DP[i] || (st.count(str) && DP[j+1]);
            }
        }
        return DP[0];
    }
};