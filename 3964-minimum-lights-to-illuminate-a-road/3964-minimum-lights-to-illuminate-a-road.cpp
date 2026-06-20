class Solution {
public:
    int minLights(vector<int>& lights) 
    {
        int n = lights.size();
        vector<pair<int,int>>intervals;
        int pos = 0;
        for(int l : lights)
        {
            if(l != 0)
            {
                intervals.push_back({max(0,pos-l),min(n-1,pos+l)});
            }
            pos++;
        }
        intervals.push_back({n,n});//to take of last empty segment.

        sort(intervals.begin(),intervals.end());

        int end = -1;
        int ans = 0;
        for(auto [first,second] : intervals)
        {
            if(first - 1 > end)
            {
                int len = (first-end-1);
                ans += ceil((double)len/3.0);
                end = second;

            }
            else
            {
                end = max(end,second);
            }
        }

        return ans;
    }
};