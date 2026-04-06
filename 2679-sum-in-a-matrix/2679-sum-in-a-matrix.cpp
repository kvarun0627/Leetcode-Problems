class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) 
    {
        int sum = 0;
        int m = nums.size();
        int n = nums[0].size();
        for (auto &row : nums) 
        {
            sort(row.begin(), row.end());
        }
        for(int i=0 ; i<n ; i++)
        {
            int maxi = 0;
            for(int j=0 ; j<m ; j++)
            {
                maxi = max(maxi , nums[j][i]);
            }
            sum += maxi;
        }
        return sum;
    }
};