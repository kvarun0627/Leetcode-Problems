class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int>mp(26,0);
        int cnt=0;
        for(char c:s1)
        {
            mp[c-'a']--;
            cnt++;
        }

        int n=s2.size();
        int l=0;
        for(int i=0;i<n;i++)
        {
            mp[s2[i]-'a']++;
            if(mp[s2[i]-'a']<=0)
            {
                cnt--;
            }
            while(mp[s2[i]-'a']>0)
            {
                mp[s2[l]-'a']--;
                if(mp[s2[l]-'a']<0)
                {
                    cnt++;
                }
                l++;
            }
            if(cnt==0)
            {
                return true;
            }
        }
        return false;
    }
};