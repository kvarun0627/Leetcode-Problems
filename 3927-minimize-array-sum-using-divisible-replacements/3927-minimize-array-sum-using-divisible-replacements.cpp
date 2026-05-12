class Solution {
public:
    long long minArraySum(vector<int>& nums) 
    {
        int maxi = *max_element(nums.begin(),nums.end());
        vector<int>Maping(maxi+1,-1);

        for(int num : nums)
        {
            Maping[num] = num;
        }

        for(int i=1 ; i <=  maxi ; i++)
        {
            if(Maping[i] != i)
            {
                continue;
            }

            for(int j = i ; j <= maxi ; j+=i)
            {
                if(Maping[j] == j)
                {
                    Maping[j] = i;
                }
            }
        }

        long long sum = 0;
        for(int num : nums)
        {
            if(Maping[num] != -1)
            {
                sum += Maping[num];
            }
        }

        return sum;
    }
};