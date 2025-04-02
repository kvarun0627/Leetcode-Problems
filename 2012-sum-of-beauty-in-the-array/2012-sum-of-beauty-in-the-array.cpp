class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int n=nums.size();
        vector<bool>suffix(n,false);
        int min_s=nums[n-1];
        for(int i=n-2;i>=1;i--)
        {
            suffix[i]=nums[i]<min_s?true:false;
            min_s=min(min_s,nums[i]);
        }
        int max_p=nums[0];
        int ans=0;
        for(int i=1;i<n-1;i++)
        {
            if(max_p<nums[i] && suffix[i])
            {
                ans+=2;
            }
            else if(nums[i]>nums[i-1] && nums[i]<nums[i+1])
            {
                ans+=1;
            }
            max_p=max(nums[i],max_p);
        }
        return ans;
    }
};