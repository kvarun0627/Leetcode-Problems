/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode*ans;
    bool LCA(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if(!root)
        {
            return false;
        }
        bool curr=(root==p || root==q);
        bool left=LCA(root->left,p,q);
        bool right=LCA(root->right,p,q);

        if(left && right)
        {
            ans=root;
        }
        else if(curr && (left || right))
        {
            ans=root;
        }

        return curr || left || right;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        LCA(root,p,q);
        return ans;
    }
};