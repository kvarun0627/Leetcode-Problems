class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        sort(nums.begin(),nums.end());
        int maxi=0;
        unordered_map<int,int>mp;
        int n=nums.size();
        int ans;
        for(int i=n-1;i>=0;i--)
        {
            maxi=max(maxi,mp[nums[i]%space]);
            if(maxi<=mp[nums[i]%space])
            {
                maxi=mp[nums[i]%space];
                ans=nums[i];
            }
            mp[nums[i]%space]++;
        }
        return ans;
    }
};