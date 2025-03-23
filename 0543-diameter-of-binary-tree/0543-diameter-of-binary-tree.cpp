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
    int DFS(TreeNode*root)
    {
        if(!root) return 0;
        int right=DFS(root->right);
        int left=DFS(root->left);
        ans=max(ans,right+left);
        return max(right,left)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        DFS(root);
        return ans;
    }
};