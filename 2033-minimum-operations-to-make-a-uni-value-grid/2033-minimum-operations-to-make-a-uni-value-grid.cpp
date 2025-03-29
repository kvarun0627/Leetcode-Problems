class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int>numbers;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                numbers.push_back(grid[i][j]);
            }
        }

        int total_len=n*m;
        nth_element(numbers.begin(),numbers.begin()+total_len/2,numbers.end());
        int final_common_number=numbers[total_len/2];
        int ops=0;
        for(int num:numbers)
        {
            if(final_common_number%x!=num%x) return -1;
            ops+=abs(num-final_common_number)/x;
        }
        return ops;
    }
};