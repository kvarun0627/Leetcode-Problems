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
    void construct_graph(TreeNode*root,unordered_map<int,vector<int>>&Graph)
    {
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty())
        {
            TreeNode*node=q.front();
            q.pop();

            if(node->right)
            {
                q.push(node->right);
                Graph[node->val].push_back(node->right->val);
                Graph[node->right->val].push_back(node->val);
            }
            if(node->left)
            {
                q.push(node->left);
                Graph[node->val].push_back(node->left->val);
                Graph[node->left->val].push_back(node->val);
            }
        }
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int,vector<int>>Graph;
        construct_graph(root,Graph);
        queue<pair<int,int>>Q;
        Q.push({start,-1});
        int lvl=0;
        while(!Q.empty())
        {
            int n=Q.size();
            while(n--)
            {
                auto [node,parent]=Q.front();
                Q.pop();
                for(int V:Graph[node])
                {
                    if(V==parent) continue;
                    Q.push({V,node});
                }
            }
            lvl++;
        }
        return lvl-1;
    }
};