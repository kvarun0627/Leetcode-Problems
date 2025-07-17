class Solution {
public:
    int subarraysWithLessThanKDistinct(vector<int>&nums,int k)
    {
        unordered_map<int,int>mp;
        int l=0;
        int ans=0;
        int n=nums.size();
        for(int r=0;r<n;r++)
        {
            mp[nums[r]]++;
            while(mp.size()>k)
            {
                mp[nums[l]]--;
                if(mp[nums[l]]==0)
                {
                    mp.erase(nums[l]);
                }
                l++;
            }
            ans+=r-l+1;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) 
    {
        return subarraysWithLessThanKDistinct(nums,k)-subarraysWithLessThanKDistinct(nums,k-1);   
    }
};