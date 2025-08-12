class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        deque<pair<long long,int>>dq;
        int ans=INT_MAX;
        long long prefix_sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            prefix_sum+=nums[i];
            if(prefix_sum>=k)
            {
                ans=min(ans,i+1);
            }
            while(!dq.empty() && dq.back().first>=prefix_sum)
            {
                dq.pop_back();
            }
            dq.push_back({prefix_sum,i});
            while(!dq.empty() && prefix_sum-dq.front().first>=k)
            {
                ans=min(ans,i-dq.front().second);
                dq.pop_front();
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};