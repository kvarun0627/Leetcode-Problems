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
    
    int reccur(TreeNode*root,bool rob,unordered_map<TreeNode*,unordered_map<bool,int>>&DP)
    {
        if(!root)
        {
            return 0;
        }

        if(DP[root].find(rob)!=DP[root].end()) return DP[root][rob];

        int right_take=0;
        int left_take=0;
        int take=0;
        
        if(!rob)
        {
            right_take=reccur(root->right,true,DP);
            left_take=reccur(root->left,true,DP);
            take=root->val+right_take+left_take;
        }

        int right_skip=reccur(root->right,false,DP);
        int left_skip=reccur(root->left,false,DP);
        int skip=right_skip+left_skip;

        return DP[root][rob]=max(take,skip);
    }
    int rob(TreeNode* root) {
        unordered_map<TreeNode*,unordered_map<bool,int>>DP;
        return reccur(root,false,DP);
    }
};