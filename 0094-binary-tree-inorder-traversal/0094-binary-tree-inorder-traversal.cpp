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
    vector<int> inorder_morris_traversal(TreeNode*root)
    {
        TreeNode*curr=root;
        vector<int>ans;
        while(curr!=nullptr)
        {
            TreeNode*pre=curr->left;
            if(!pre)
            {
                ans.push_back(curr->val);
                curr=curr->right;
            }
            else
            {
                TreeNode*mover=pre;
                while(mover->right!=nullptr)
                {
                    mover=mover->right;
                }
                mover->right=curr;
                curr->left=nullptr;
                curr=pre;
            }
        }
        return ans;
    }
    vector<int> inorderTraversal(TreeNode* root) {
        return inorder_morris_traversal(root);
    }
};