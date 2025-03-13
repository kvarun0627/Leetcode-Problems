class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int>diff_array(n+1,0);
        for(auto q:queries)
        {
            int start=q[0];
            int end=q[1];
            diff_array[start]+=1;
            diff_array[end+1]-=1;
        }

        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=diff_array[i];
            if(sum<nums[i]) return false;
        }
        return true;
    }
};