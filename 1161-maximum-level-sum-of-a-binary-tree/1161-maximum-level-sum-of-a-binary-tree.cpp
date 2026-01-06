/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxLevelSum(TreeNode* root) 
    {
        queue<TreeNode*>q;
        q.push(root);

        int level=1;
        long long maxi=LLONG_MIN;
        int ans=0;
        while(!q.empty())
        {
            int n=q.size();
            long long sum=0;
            for(int i=0;i<n;i++)
            {
                auto node=q.front();
                q.pop();
                sum+=node->val;
                if(node->right)
                {
                    q.push(node->right);
                }
                if(node->left)
                {
                    q.push(node->left);
                }
            }
            if(sum>maxi)
            {
                ans=level;
                maxi=sum;
            }
            level++;
        }
        return ans;
    }
};