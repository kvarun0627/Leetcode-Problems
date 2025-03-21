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
    bool flag=true;
    int height(TreeNode*root)
    {
        if(!root) return 0;

        int right=height(root->right);
        int left=height(root->left);
        if(abs(left-right)>1)
        {
            flag=false;
        }
        return max(right,left)+1;
    }
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        int n=height(root);
        return flag;
    }
};