class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
        int n=nums.size();
        if(n%k!=0)
        {
            return false;
        }

        int tot=n/k;

        unordered_map<int,int>mp;
        for(int num:nums)
        {
            mp[num]++;
        }

        for(auto it=mp.begin();it!=mp.end();it++)
        {
            if(it->second>tot)
            {
                return false;
            }
        }

        return true;
    }
};