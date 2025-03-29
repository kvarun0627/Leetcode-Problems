class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int i=0;
        int n=intervals.size();
        vector<vector<int>>ans;
        while(i<n)
        {
            int start_i=intervals[i][0];
            int end_i=intervals[i][1];
            i++;
            while(i<n && intervals[i][0]<=end_i)
            {
                end_i=max(end_i,intervals[i][1]);
                i++;
            }
            ans.push_back({start_i,end_i});
        } 
        return ans;
    }
};