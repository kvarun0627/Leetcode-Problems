class Solution {
public:
    bool ans=false;
    void reccur(vector<vector<char>>& board,int r,int c,vector<set<char>>&rows,vector<set<char>>&cols,vector<set<char>>&grids)
    {
        if(c==9)
        {
            r=r+1;
            c=0;
        }
        if(r==9)
        {
            ans=true;
            return ;
        }

        if(board[r][c]!='.')
        {
            reccur(board,r,c+1,rows,cols,grids);
            return ;
        }

        for(char num='1';num<='9';num++)
        {
            if(!rows[r].count(num) && !cols[c].count(num) && !grids[3*(r/3)+c/3].count(num))
            {
                board[r][c]=num;
                rows[r].insert(num);
                cols[c].insert(num);
                grids[3*(r/3)+c/3].insert(num);
                reccur(board,r,c+1,rows,cols,grids);
                if(ans)
                {
                    return ;
                }
                board[r][c]='.';
                rows[r].erase(num);
                cols[c].erase(num);
                grids[3*(r/3)+c/3].erase(num);
            }
        }
    }
    void solveSudoku(vector<vector<char>>& board) {
       vector<set<char>>rows(9),cols(9),grids(9);
       for(int i=0;i<9;i++)
       {
          for(int j=0;j<9;j++)
          {
            if(board[i][j]=='.')
            {
                continue;
            }
            rows[i].insert(board[i][j]);
            cols[j].insert(board[i][j]);
            grids[3*(i/3)+j/3].insert(board[i][j]);
          }
       }

       reccur(board,0,0,rows,cols,grids);
    }
};