class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int top=0;
        int down=m-1;
        int left=0;
        int right=n-1;
        vector<int>ans;
        while(top<=down && left<=right)
        {
            for(int i=left;i<=right;i++)
            {
                ans.push_back(matrix[top][i]);
            }
            top++;
            for(int i=top;i<=down;i++)
            {
                ans.push_back(matrix[i][right]);
            }
            right--;
            if(top<=down)
            {
                for(int i=right;i>=left;i--)
                {
                    ans.push_back(matrix[down][i]);
                }
                down--;
            }
            if(left<=right)
            {
                for(int i=down;i>=top;i--)
                {
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return ans;
    }
};