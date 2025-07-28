class Solution {
public:
    int solve(int n,int col,vector<bool>&upper_dia,vector<bool>&lower_dia,vector<bool>&curr_row)
    {
        if(col==n)
        {
            return 1;
        }

        int ans=0;
        for(int row=0;row<n;row++)
        {
            if(!upper_dia[n+(col-row)-1] && !lower_dia[(row+col)] && !curr_row[row])
            {
                upper_dia[n+(col-row)-1]=true;
                lower_dia[row+col]=true;
                curr_row[row]=true;
                ans+=solve(n,col+1,upper_dia,lower_dia,curr_row);
                upper_dia[n+(col-row)-1]=false;
                lower_dia[row+col]=false;
                curr_row[row]=false;
            }
        }
        return ans;
    }
    int totalNQueens(int n) {
        vector<bool>upper_dia(2*n-1,false),lower_dia(2*n-1,false),curr_row(n,false);
        return solve(n,0,upper_dia,lower_dia,curr_row);
    }
};