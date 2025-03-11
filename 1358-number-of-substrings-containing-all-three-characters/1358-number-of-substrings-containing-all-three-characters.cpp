class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        vector<int>freq(3,0);
        int right=0;
        int left=0;
        int ans=0;
        while(right<n)
        {
            freq[s[right]-'a']++;
            while(freq[0] && freq[1] && freq[2])
            {
                ans+=(n-right);
                freq[s[left++]-'a']--;
            }
            right++;
        }
        return ans;
    }
};