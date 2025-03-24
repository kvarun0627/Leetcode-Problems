class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        int present=meetings[0][0]-1;;
        int end=meetings[0][1]+1;
        int n=meetings.size();
        for(int i=1;i<n && end<=days ;i++)
        {
            if(meetings[i][0]>end)
            {
                present++;
            }
            end=max(end,meetings[i][1]+1);
        }
        if(end<=days)
        {
            present++;
        }
        return present;
    }
};