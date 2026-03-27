class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) 
    {
        map<int,int>mp;
        for(int x:nums1)
        {
            mp[x]++;
        }
        for(int x:nums2)
        {
            if(mp.find(x)==mp.end())
            {
                mp[x]++;
            }
            else
            {
                mp[x]--;
                if(mp[x] == 0)
                {
                    mp.erase(x);
                }
            }
        }

        int ans = 0;
        for(auto it = mp.begin() ; it!=mp.end() ; it++)
        {
            if((it->second)%2 == 1)
            {
                return -1;
            }
            else
            {
                ans += (it->second)/2;
            }
        }
        return ans;
    }
};