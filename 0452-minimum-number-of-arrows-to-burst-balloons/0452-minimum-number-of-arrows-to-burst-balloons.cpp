class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int curr_start=points[0][0];
        int curr_end=points[0][1];
        int n=points.size();
        int i=0;
        int arrows=0;
        while(i<n)
        {
            while(i<n && points[i][0]<=curr_end)
            {
                curr_start=points[i][0];
                curr_end=min(points[i][1],curr_end);
                i++;
            }
            arrows++;
            if(i<n)
            {
                curr_start=points[i][0];
                curr_end=points[i][1];
            }
        }
        return arrows;
    }
};