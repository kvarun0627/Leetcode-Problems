class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char,int>mp;
        int cnt=0;
        for(char c:p)
        {
            mp[c]--;
            cnt++;
        }

        vector<int>ans;
        int n=s.size();
        int l=0;
        for(int i=0;i<n;i++)
        {
            mp[s[i]]++;
            if(mp[s[i]]<=0)
            {
                cnt--;
            }
            while(mp[s[i]]>0)
            {
                mp[s[l]]--;
                if(mp[s[l]]<0)
                {
                    cnt++;
                }
                l++;
            }
            if(cnt==0)
            {   
                ans.push_back(l);
            }
        }
        return ans;
    }
};