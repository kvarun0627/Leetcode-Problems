class Solution {
public:
    bool is_vowel(char c)
    {
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
    }
    int maxVowels(string s, int k) {
        int v=0;
        int n=s.size();
        int j=0;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            v=v+is_vowel(s[i]);
            if(i>=k-1)
            {
                ans=max(ans,v);
                v=v-is_vowel(s[j]);
                j++;
            }
        }
        return ans;
    }
};