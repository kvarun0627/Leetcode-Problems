class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>mp;
        int m=t.size();
        for(auto c:t)
        {
            mp[c]++;
        }

        int l=0;
        int n=s.size();
        int cnt=0;
        int min_len=INT_MAX;
        int start_idx;
        for(int r=0;r<n;r++)
        {
            if(mp.find(s[r])!=mp.end())
            {
                if(mp[s[r]]>0)
                {
                    cnt++;
                }
                mp[s[r]]--;
            }
            else
            {
                mp[s[r]]=-1;
            }

            while(cnt==m)
            {
                if(min_len>=r-l+1)
                {
                    min_len=r-l+1;
                    start_idx=l;
                }
                mp[s[l]]++;
                if(mp[s[l]]>0)
                {
                    cnt--;
                }
                l++;
            }
        }
        if(min_len==INT_MAX)
        {
            return "";
        }
        return s.substr(start_idx,min_len);
    }
};