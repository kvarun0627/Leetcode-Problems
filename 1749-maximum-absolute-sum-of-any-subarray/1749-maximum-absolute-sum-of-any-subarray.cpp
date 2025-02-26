class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int minsum=0;
        int maxsum=0;
        int sum=0;
        int result=0;
        for(int i:nums)
        {
            sum+=i;
            result=max(result,max(abs(sum-minsum),abs(sum-maxsum)));
            minsum=min(minsum,sum);
            maxsum=max(maxsum,sum);
        }
        return result;
    }
};