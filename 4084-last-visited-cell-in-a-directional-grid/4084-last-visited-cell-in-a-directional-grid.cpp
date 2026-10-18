class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();

        set<pair<int,int>>st;
        st.insert({0,0});

        int i = 0;
        int j = 0;
        while(true)
        {
            char c = grid[i][j];
            int oi = i;
            int oj = j;
            if(c == 'R')
            {
                j++;
            }
            else if(c == 'L')
            {
                j--;
            }
            else if(c == 'U')
            {
                i--;
            }
            else
            {
                i++;
            }

            if(i<0 || i>=n || j<0 || j>=m || st.count({i,j}))
            {
                return {oi,oj};
            }

            st.insert({i,j});
        }
        return {-1,-1};
    }
};