class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto itl=lower_bound(nums.begin(),nums.end(),target);
        auto itu=upper_bound(nums.begin(),nums.end(),target);
        if(itl==itu)
        {
            return {-1,-1};
        }
        int left=itl-nums.begin();
        int right=itu-nums.begin();
        return {left,right-1};
    }
};