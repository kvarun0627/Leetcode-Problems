class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
       vector<set<char>>rows(9),cols(9),grid(9);
       for(int i=0;i<9;i++)
       {
          for(int j=0;j<9;j++)
          {
            if(board[i][j]=='.')
            {
                continue;
            }

            if(!rows[i].count(board[i][j]))
            {
                rows[i].insert(board[i][j]);
            }
            else
            {
                return false;
            }

            if(!cols[j].count(board[i][j]))
            {
                cols[j].insert(board[i][j]);
            }
            else
            {
                return false;
            }

            if(!grid[3*(i/3)+j/3].count(board[i][j]))
            {
                grid[3*(i/3)+j/3].insert(board[i][j]);
            }
            else
            {
                return false;
            }

          }
       }
       return true; 
    }
};