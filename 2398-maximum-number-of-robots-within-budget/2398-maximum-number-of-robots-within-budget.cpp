class Solution {
public:
    bool possible(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget,int mid,int n)
    {
        deque<int>dq;
        long long sum=0;
        for(int i=0;i<mid;i++)
        {
            while(!dq.empty() && chargeTimes[dq.back()]<chargeTimes[i])
            {
                dq.pop_back();
            }
            dq.push_back(i);
            sum+=runningCosts[i];
        }

        if((long long)(chargeTimes[dq.front()]+(long long)mid*sum)<=budget)return true;

        for(int i=mid;i<n;i++)
        {
            if(!dq.empty() && dq.front()==i-mid)
            {
                dq.pop_front();
            }

            while(!dq.empty() && chargeTimes[dq.back()]<chargeTimes[i])
            {
                dq.pop_back();
            }
            dq.push_back(i);

            sum+=(runningCosts[i]-runningCosts[i-mid]);

            if((long long)(chargeTimes[dq.front()]+(long long)mid*sum)<=budget)return true;
        }
        return false;
    }
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        int n=chargeTimes.size();
        int high=n;
        int low=1;
        int ans=0;
        while(high>=low)
        {
            int mid=(low+high)/2;
            if(possible(chargeTimes,runningCosts,budget,mid,n))
            {
                ans=mid;
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return ans;
    }
};