class Solution {
public:
    bool checkEqualPartitions(vector<int>& nums, long long target) 
    {
        int n = nums.size();
        int mask = 1<<n;
        for(int i=1;i<mask;i++)
        {
            long long left = 1;
            long long right = 1;
            for(int bit=0;bit<n;bit++)
            {
                if(i & (1<<bit))
                {
                    if(left > 1e18/nums[bit])
                    {
                        continue;
                    }
                    left *= nums[bit];
                }
                else
                {
                    if(right>1e18/nums[bit])
                    {
                        continue;
                    }
                    right*=nums[bit];
                }
            }
            cout<<i << " "<<left<<" "<<right<<endl;
            if(left==target && right==target)
            {
                return true;
            }
        }
        return false;
    }
};