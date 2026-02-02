class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist)
    {
        int n=nums.size();
        multiset<int>low,high;
        //size(low)<=k-1;
        //elements in low <= elements in high

        long long mini = LLONG_MAX;
        long long sum=nums[0];
        auto balance = [&]()
        {
            while(low.size()<k-1 && !high.empty())
            {
                low.insert(*high.begin());
                sum+=*high.begin();
                high.erase(high.begin());
            }
            while(low.size()>k-1)
            {
                high.insert(*prev(low.end()));
                sum-=*prev(low.end());
                low.erase(prev(low.end()));
            }
        };

        auto add = [&](int x)
        {
            if(low.empty() || *prev(low.end()) >= x)
            {
                low.insert(x);
                sum+=x;
            }
            else
            {
                high.insert(x);
            }
            balance();
        };

        auto remove=[&](int x)
        {
            if(*prev(low.end()) >= x)
            {
                low.erase(low.find(x));
                sum-=x;
            }
            else
            {
                high.erase(high.find(x));
            }
            balance();
        };

        for(int i=1;i<n;i++)
        {
            add(nums[i]);
            if(i>=dist+1)
            {
                mini=min(mini,sum);
                remove(nums[i-dist]);
            }
        }

        return mini;
    }
};