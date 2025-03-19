class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            int j;
            if(i>0 && nums[i]==nums[i-1])
            {
                continue;
            }
            int new_target=-nums[i];

            j=i+1;
            int k=n-1;
            while(j<k)
            {
                if(nums[j]+nums[k]==new_target)
                {
                    ans.push_back({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                    while(j<k && nums[j]==nums[j-1] && nums[k]==nums[k+1])
                    {
                        j++;
                        k--;
                    }
                }
                else if(nums[j]+nums[k]>new_target)
                {
                    k--;
                }
                else
                {
                    j++;
                }
            }
        }
        return ans;
    }
};