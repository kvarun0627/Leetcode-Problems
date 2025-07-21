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
    int ans=0;
    void helper(TreeNode*root,int num)
    {
        if(!root)
        {
            return ;
        }
        int new_num=num*10+root->val;
        if(!root->right && !root->left)
        {
            ans+=new_num;
            return ;
        }
        helper(root->right,new_num);
        helper(root->left,new_num);
    }
    int sumNumbers(TreeNode* root) {
        helper(root,0);
        return ans;
    }
};