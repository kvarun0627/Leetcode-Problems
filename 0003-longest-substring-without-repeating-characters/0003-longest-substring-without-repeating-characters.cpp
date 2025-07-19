class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        unordered_map<char,int>mp;
        int ans=0;
        int l=0;
        for(int r=0;r<n;r++)
        {
            if(mp.find(s[r])!=mp.end())
            {
                if(mp[s[r]]>=l)
                {
                    l=mp[s[r]]+1;
                }
            }
            mp[s[r]]=r;
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};