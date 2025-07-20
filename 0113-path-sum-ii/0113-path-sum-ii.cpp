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
    vector<vector<int>>ans;
    void helper(TreeNode* root,int k,vector<int>&path)
    {
        if(!root)
        {
            return ;
        }
        if(!root->right && !root->left)
        {
            if(k==root->val)
            {
                path.push_back(root->val);
                ans.push_back(path);
                path.pop_back();
            }
            return ;
        }
        path.push_back(root->val);
        helper(root->right,k-root->val,path);
        helper(root->left,k-root->val,path);
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>path;
        helper(root,targetSum,path);
        return ans;
    }
};