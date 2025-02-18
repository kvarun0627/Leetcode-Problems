class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len=0;
        int n=nums.size();
        vector<int>temp;
        for(int i=0;i<n;i++)
        {
            if(temp.empty() || nums[i]>temp.back())
            {
                temp.push_back(nums[i]);
                len++;
            }
            else
            {
                int idx=lower_bound(temp.begin(),temp.end(),nums[i])-temp.begin();
                temp[idx]=nums[i];
            }
        }
        return len;
    }
};