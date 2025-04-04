class Solution {
public:
    int cost_to_remove(int prevIdx,int Idx,vector<int>& nums,int n,vector<vector<int>>&DP)
    {
        if(Idx==n) return nums[prevIdx];
        if(Idx==n-1) return max(nums[prevIdx],nums[Idx]);
        if((DP[Idx][prevIdx]!=-1))
        {
            return DP[Idx][prevIdx];
        }
        int first=max(nums[Idx],nums[Idx+1])+cost_to_remove(prevIdx,Idx+2,nums,n,DP);
        int middle=max(nums[prevIdx],nums[Idx+1])+cost_to_remove(Idx,Idx+2,nums,n,DP);
        int last=max(nums[prevIdx],nums[Idx])+cost_to_remove(Idx+1,Idx+2,nums,n,DP);
        return DP[Idx][prevIdx]=min({first,middle,last});
    }
    int minCost(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>DP(n,vector<int>(n,-1));
        return cost_to_remove(0,1,nums,n,DP);
    }
};