class Solution {
public:
    long long countStableSubarrays(vector<int>& capacity) {
        int n=capacity.size();
        vector<long long>pref(n+1,0);
        for(int i=1;i<=n;i++)
            {
                pref[i]=capacity[i-1]+pref[i-1];
            }
        long long ans=0;
        unordered_map<int,unordered_map<long long,int>>mp;
        for(int i=0;i<n;i++)
        {
            int ar=capacity[i];
            long long prefl=pref[i]-ar;
            int al=ar;
            if(mp.find(al)!=mp.end() && mp[al].find(prefl)!=mp[al].end())
            {
                ans+=(mp[al][prefl]);
                if(capacity[i-1]==ar && pref[i]==prefl)
                {
                    ans-=1;
                }
            }
            mp[ar][pref[i+1]]++;
        }
        return ans;
        
    }
};