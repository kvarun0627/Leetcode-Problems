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
    int max_height=-1;
    void helper(TreeNode*root,int ht,vector<int>&rt)
    {
        if(!root)
        {
            return ;
        }
        if(ht>max_height)
        {
            rt.push_back(root->val);
            max_height=ht;
        }
        helper(root->right,ht+1,rt);
        helper(root->left,ht+1,rt);
        return ;
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>rt;
        helper(root,0,rt);
        return rt;
    }
};