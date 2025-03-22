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
    int ans=INT_MIN;
    int PathSum(TreeNode*root)
    {
        if(!root) return 0;

        int left=max(0,PathSum(root->left));
        int right=max(0,PathSum(root->right));
        ans=max(ans,root->val+left+right);
        return max(left,right)+root->val;
    }
    int maxPathSum(TreeNode* root) {
        PathSum(root);
        return ans;
    }
};