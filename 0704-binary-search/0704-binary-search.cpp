class Solution {
public:
    int search(vector<int>& nums, int target) {
        int idx=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        if(nums[idx]!=target) return -1;
        return idx;
    }
};