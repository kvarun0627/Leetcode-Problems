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
    int max_depth=-1;
    void RightVeiw(TreeNode*root,int depth,vector<int>&ans)
    {
        if(!root) return;

        depth++;
        if(depth>max_depth)
        {
            ans.push_back(root->val);
            max_depth=depth;
        }
        RightVeiw(root->right,depth,ans);
        RightVeiw(root->left,depth,ans);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        RightVeiw(root,-1,ans);
        return ans;
    }
};