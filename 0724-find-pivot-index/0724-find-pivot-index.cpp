class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int right=accumulate(nums.begin(),nums.end(),0);
        int left=0;
        int idx=0;
        for(int num:nums)
        {
            
            right-=num;
            if(left==right)
            {
                return idx;
            }
            left+=num;
            idx++;
        }
        
        return -1;
    }
};