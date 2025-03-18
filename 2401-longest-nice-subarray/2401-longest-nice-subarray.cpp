class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int left=0;
        int right=0;
        int n=nums.size();
        int len=1;
        int mask=0;
        while(right<n)
        {
           if(!(mask & nums[right]))
            {
                mask|=nums[right];
                right++;
                len=max(len,right-left);
            }
            else
            {
                mask^=nums[left];
                left++;
            }
        }
        return len;
    }
};