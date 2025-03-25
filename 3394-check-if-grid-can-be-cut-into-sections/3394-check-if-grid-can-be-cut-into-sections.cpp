class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        int m=rectangles.size();
        vector<vector<int>>horizontal_lines;
        vector<vector<int>>vertical_lines;
        for(int i=0;i<m;i++)
        {
            int x1=rectangles[i][0];
            int y1=rectangles[i][1];
            int x2=rectangles[i][2];
            int y2=rectangles[i][3];
            horizontal_lines.push_back({x1,x2});
            vertical_lines.push_back({y1,y2});
        }
        sort(horizontal_lines.begin(),horizontal_lines.end());
        sort(vertical_lines.begin(),vertical_lines.end());

        int end=horizontal_lines[0][1];
        int lines=0;
        for(int i=1;i<m;i++)
        {
            if(horizontal_lines[i][0]>=end)
            {
                lines++;
            }
            end=max(end,horizontal_lines[i][1]);
        }
        if(lines>=2) return true;

        lines=0;
        end=vertical_lines[0][1];
        for(int i=1;i<m;i++)
        {
            if(vertical_lines[i][0]>=end)
            {
                lines++;
            }
            end=max(end,vertical_lines[i][1]);
        }
        if(lines>=2) return true;

        return false;
    }
};