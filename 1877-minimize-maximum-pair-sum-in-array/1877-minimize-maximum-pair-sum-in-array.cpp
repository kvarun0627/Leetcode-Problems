class Solution {
public:
    int minPairSum(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        int j=nums.size()-1;
        int i=0;
        int maxi=0;
        while(i<j)
        {
            maxi=max(maxi,nums[j]+nums[i]);
            j--;
            i++;
        }    
        return maxi;
    }
};