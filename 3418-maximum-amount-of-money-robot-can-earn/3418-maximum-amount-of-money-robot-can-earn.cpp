class Solution {
public:
    int DP_on_grids(vector<vector<vector<int>>>& DP, vector<vector<int>>& coins, int m, int n, int x, int y, int nullify) 
    {
        if (x >= m || y >= n) return INT_MIN;

        if (x == m - 1 && y == n - 1) {
            if (coins[x][y] < 0) {
                return DP[x][y][nullify] = (nullify > 0 ? 0 : coins[x][y]);
            }
            return DP[x][y][nullify] = coins[x][y];
        }

        if (DP[x][y][nullify] != -1) return DP[x][y][nullify];

        int right = DP_on_grids(DP, coins, m, n, x, y + 1, nullify);
        int down = DP_on_grids(DP, coins, m, n, x + 1, y, nullify);
        int take = coins[x][y]+max(right,down);
        int not_take=INT_MIN;

        if(coins[x][y]<0 && nullify>0)
        {
            int right_use = DP_on_grids(DP, coins, m, n, x, y + 1, nullify-1);
            int down_use = DP_on_grids(DP, coins, m, n, x + 1, y, nullify-1);
            not_take=max(right_use,down_use);
        }

        return DP[x][y][nullify]=max(take,not_take);
    }

    int maximumAmount(vector<vector<int>>& coins) 
    {
        int m = coins.size();
        int n = coins[0].size();

        vector<vector<vector<int>>> DP(m+1,vector<vector<int>>(n+1,vector<int>(3,INT_MIN)));
        for(int x=m-1;x>=0;x--)
        {
            for(int y=n-1;y>=0;y--)
            {
                for(int nullify =2;nullify>=0;nullify--)
                {
                    if(x == m - 1 && y == n - 1) 
                    {
                        if(coins[x][y] < 0)
                        {
                            DP[x][y][nullify] = (nullify > 0 ? 0 : coins[x][y]);
                        }
                        else
                        {
                            DP[x][y][nullify] = coins[x][y];
                        }
                        continue;
                    }

                    int right = DP[x][y+1][nullify];
                    int down = DP[x+1][y][nullify];
                    int take = coins[x][y]+max(right,down);
                    int not_take=INT_MIN;

                    if(coins[x][y]<0 && nullify>0)
                    {
                        int right_use = DP[x][y+1][nullify-1];
                        int down_use = DP[x+1][y][nullify-1];
                        not_take=max(right_use,down_use);
                    }

                    DP[x][y][nullify]=max(take,not_take);
                }
            }
        }
        return max({DP[0][0][0],DP[0][0][1],DP[0][0][2]});
    }
};