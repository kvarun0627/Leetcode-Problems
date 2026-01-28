class Solution {
public:
    long long kSum(vector<int>& nums, int k) 
    {
        int n=nums.size();
        long long maxSum=0;
        for(int &num:nums)
        {
            if(num>0)
            {
                maxSum+=num;
            }
            num = abs(num);
        }
        sort(nums.begin(),nums.end());

        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
        pq.push({0,0});

        long long kthSmallest=0;
        while(k--)
        {
            auto [currSum,idx] = pq.top();
            pq.pop();
            kthSmallest=currSum;

            //Basically Doing Take / NotTake
            // since the array is sorted this method will work
            if(idx<n)
            {
                if(idx>0)
                {
                    pq.push({currSum-nums[idx-1]+nums[idx],idx+1});
                }
                pq.push({currSum+nums[idx],idx+1});
            }
            
        }

        return maxSum-kthSmallest;
    }
};