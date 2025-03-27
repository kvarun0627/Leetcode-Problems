class Solution {
public:
    int booye_moore(vector<int>&nums)
    {
        int curr_element=nums[0];
        int cnt=0;
        for(int x:nums)
        {
            if(curr_element==x)
            {
                cnt++;
            }
            else
            {
                cnt--;
                if(cnt==0)
                {
                    curr_element=x;
                    cnt=1;
                }
            }
        }
        return curr_element;
    }
    int minimumIndex(vector<int>& nums) {
        int dominant=booye_moore(nums);
        int suffix=0;
        for(int x:nums)
        {
            if(x==dominant)
            {
                suffix++;
            }
        }
        int prefix=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]==dominant)
            {
                prefix++;
                if(prefix*2>i+1 && (suffix-prefix)*2>n-i-1)
                {
                    return i;
                }
            }
        }
        return -1;
    }
};