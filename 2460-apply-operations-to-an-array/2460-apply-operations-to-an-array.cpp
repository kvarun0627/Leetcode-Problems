class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n-1;i++)
        {
            if(nums[i]==nums[i+1])
            {
                nums[i]*=2;
                nums[i+1]=0;
            }
        }
        int nz=0;
        int z=n-1;
        while(nz<z)
        {
            if(nums[z]==0)
            {
                z--;
            }
            if(nums[nz]!=0)
            {
                nz++;
            }
            if(nz<z && nums[nz]==0 && nums[z]!=0)
            {
                swap(nums[nz],nums[z]);
                z--;
                nz++;
            }
        }
        return nums;
    }
};