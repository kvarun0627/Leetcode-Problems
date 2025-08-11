class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int>mp;
        int n=s.size();
        int j=0;
        int ans=-1;
        int max_freq=0;
        for(int i=0;i<n;i++)
        {
            mp[s[i]]++;
            max_freq=max(max_freq,mp[s[i]]);
            while(i-j+1-max_freq>k)
            {
                mp[s[j]]--;
                max_freq=max(max_freq,mp[s[j]]);
                j++;
            }
            ans=max(ans,i-j+1);
        }
        return ans;
    }
};