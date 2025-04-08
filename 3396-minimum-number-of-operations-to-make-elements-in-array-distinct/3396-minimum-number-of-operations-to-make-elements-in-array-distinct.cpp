class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        bool seen[101]={false};
        int n=nums.size();

        for(int i=n-1;i>=0;i--)
        {
            if(seen[nums[i]])
            {
                return (int)floor((double)i/3)+1;
            }
            seen[nums[i]]=true;
        }
        return 0;
    }
};