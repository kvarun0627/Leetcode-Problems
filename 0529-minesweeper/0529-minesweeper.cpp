class Solution {
public:
    void BFS(vector<vector<char>>&board, vector<int>&click, vector<vector<int>>&adj, vector<vector<bool>>&vis ,int m,int n)
    {
        queue<pair<int,int>>q;
        q.push({click[0],click[1]});
        vis[click[0]][click[1]]=true;

        while(!q.empty())
        {
            auto [x,y]=q.front();
            q.pop();

            if(board[x][y]=='M')
            {
                board[x][y]='X';
                continue;
            }
            if(adj[x][y]>=1 && adj[x][y]<=8)
            {
                board[x][y]=adj[x][y]+'0';
                continue;
            }
            if(board[x][y]=='E' || board[x][y]=='B')
            {
                board[x][y]='B';
                for(int k=max(0,y-1);k<=min(n-1,y+1);k++)
                    {
                        for(int l=max(0,x-1);l<=min(m-1,x+1);l++)
                        {
                            if(k==y && l==x)
                            {
                                continue;
                            }
                            if(!vis[l][k])
                            {
                                q.push({l,k});
                                vis[l][k]=true;
                            }
                        }
                    }
            }
        }
    }
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<int>>adj(m,vector<int>(n,0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]=='M' || board[i][j]=='X')
                {
                    for(int k=max(0,j-1);k<=min(n-1,j+1);k++)
                    {
                        for(int l=max(0,i-1);l<=min(m-1,i+1);l++)
                        {
                            if(k==j && l==i)
                            {
                                continue;
                            }
                            adj[l][k]++;
                        }
                    }
                }
            }
        }
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        BFS(board,click,adj,vis,m,n);
        return board;

    }
};