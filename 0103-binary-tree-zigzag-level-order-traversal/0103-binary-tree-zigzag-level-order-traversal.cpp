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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)
        {
            return {};
        }
        queue<TreeNode*>q;
        q.push(root);
        vector<vector<int>>ans;
        bool toRight=true;
        while(!q.empty())
        {
            int n=q.size();
            vector<int>lvl(n);
            for(int i=0;i<n;i++)
            {
                TreeNode* node=q.front();
                q.pop();
                int index= toRight?n-i-1:i;
                lvl[index]=node->val;
                if(node->right)
                {
                    q.push(node->right);
                }
                if(node->left)
                {
                    q.push(node->left);
                }
            }
            ans.push_back(lvl);
            toRight=!toRight;
        }
        return ans;
    }
};