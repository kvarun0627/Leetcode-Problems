class Solution {
public:
    int BS(vector<vector<int>>&intervals,int x,int n)
    {
        int low=0;
        int high=n-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(intervals[mid][0]>=x)
            {
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return low;
    }

    int memo(int idx,vector<vector<int>>&intervals,int n,vector<int>&profit,vector<int>&DP)
    {
        if(idx>=n)
        {
            return 0;
        }
        if(DP[idx]!=-1)
        {
            return DP[idx];
        }
        int skip=memo(idx+1,intervals,n,profit,DP);
        int next_idx=BS(intervals,intervals[idx][1],n);
        int not_skip=intervals[idx][2]+memo(next_idx,intervals,n,profit,DP);
        return DP[idx]=max(skip,not_skip);
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>>intervals;
        int n=startTime.size();
        for(int i=0;i<n;i++)
        {
            intervals.push_back({startTime[i],endTime[i],profit[i]});
        }
        sort(intervals.begin(),intervals.end());
        vector<int>DP(n,-1);
        // for(int i=n-1;i>=0;i--)
        // {
        //     int skip=DP[i+1];
        //     int next_idx=BS(intervals,intervals[idx][1],n);
        //     int not_skip=intervals[idx][2]+memo(next_idx,intervals,n,profit);
        //     return max(skip,not_skip);
        // }
        return memo(0,intervals,n,profit,DP);
    }
};