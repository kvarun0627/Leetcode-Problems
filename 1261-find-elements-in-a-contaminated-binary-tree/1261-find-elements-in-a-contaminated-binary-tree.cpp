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
class FindElements {
public:
    vector<int>nodes;
    int size=0;
    FindElements(TreeNode* root) {
        root->val=0;
        queue<TreeNode*>q;
        q.push(root);
        size++;
        while(!q.empty())
        {
            TreeNode*node=q.front();
            q.pop();
            int n=node->val;
            nodes.push_back(n);
            if(node->left)
            {
                node->left->val=2*n+1;
                q.push(node->left);
                size++;
            }
            if(node->right)
            {
                node->right->val=2*n+2;
                q.push(node->right);
                size++;
            }
        }
    }
    
    bool find(int target) {
        int idx=lower_bound(nodes.begin(),nodes.end(),target)-nodes.begin();
        if(nodes[idx]!=target) return false;
        return true;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */