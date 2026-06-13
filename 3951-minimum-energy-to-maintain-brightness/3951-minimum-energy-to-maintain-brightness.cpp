class Solution {
public:
    long long minEnergy(int n, int brightness, vector<vector<int>>& intervals) 
    {
        int b = ceil((double)brightness/3.0);
        sort(intervals.begin() , intervals.end());

        int m = intervals.size();
        long long ans = 0;
        for(int i = 0 ; i < m ;)
        {
            int start = intervals[i][0];
            int end = intervals[i][1];
            while(i < m && intervals[i][0] <= end)
            {
                end = max(end,intervals[i][1]);
                i++;
            }
            ans += (long long)(end-start+1)*b;
        }
        return ans;
    }
};