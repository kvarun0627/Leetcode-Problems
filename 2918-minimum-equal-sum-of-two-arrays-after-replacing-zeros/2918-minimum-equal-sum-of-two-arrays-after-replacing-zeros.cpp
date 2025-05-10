class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1=0;
        int z1=0;
        long long sum2=0;
        int z2=0;
        for(int i:nums1)
        {
            sum1+=i;
            if(i==0) 
            {
                z1++;sum1++;
            }
        }
        for(int i:nums2)
        {
            sum2+=i;
            if(i==0) 
            {
                z2++;sum2++;
            }
        }

        if((sum2>sum1 && z1==0) || (sum1>sum2 && z2==0)) return -1;
        
        return max(sum2,sum1);
    }
};