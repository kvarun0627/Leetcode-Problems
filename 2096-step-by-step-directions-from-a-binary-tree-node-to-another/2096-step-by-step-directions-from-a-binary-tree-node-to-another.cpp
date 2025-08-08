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
    // int N = 1e5;
    // int LOG = ceil(log2(1e5));

    // // We'll store UP table and Depth globally for simplicity
    // unordered_map<TreeNode*, unordered_map<int, TreeNode*>> UP;
    // unordered_map<TreeNode*, int> Depth;

    // void DFS(TreeNode* root, TreeNode* parent) {
    //     if (!root) return;

    //     Depth[root] = Depth[parent] + 1;
    //     UP[root][0] = parent;

    //     for (int j = 1; j <= LOG; j++) {
    //         if (UP[root][j - 1] != nullptr)
    //             UP[root][j] = UP[UP[root][j - 1]][j - 1];
    //         else
    //             UP[root][j] = nullptr;
    //     }

    //     DFS(root->left, root);
    //     DFS(root->right, root);
    // }

    // TreeNode* Lift(TreeNode* node, int k) {
    //     for (int j = 0; j <= LOG; j++) {
    //         if (node == nullptr) break;
    //         if (k & (1 << j)) {
    //             node = UP[node][j];
    //         }
    //     }
    //     return node;
    // }

    // TreeNode* LCA(TreeNode* u, TreeNode* v) {
    //     if (Depth[u] < Depth[v]) swap(u, v);

    //     // Step 1: Bring u and v to same depth
    //     u = Lift(u, Depth[u] - Depth[v]);

    //     if (u == v) return u;

    //     // Step 2: Lift both up together until their parents match
    //     for (int j = LOG; j >= 0; j--) {
    //         if (UP[u][j] != UP[v][j]) {
    //             u = UP[u][j];
    //             v = UP[v][j];
    //         }
    //     }

    //     // Step 3: Return parent
    //     return UP[u][0];
    // }

    void DFS(TreeNode*root,int target,string&s,string&ans)
    {
        if(!root)
        {
            return ;
        }
        if(root->val==target)
        {
            ans=s;
            return ;
        }
        s+='L';
        DFS(root->left,target,s,ans);
        s.pop_back();
        s+='R';
        DFS(root->right,target,s,ans);
        s.pop_back();
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string s="";
        string source;
        string target;
        DFS(root,startValue,s,source);
        DFS(root,destValue,s,target);

        int i=0;
        int j=0;
        int n=source.size();
        int m=target.size();
        while(source[i]==target[j])
        {
            i++;j++;
        }

        string A="";
        string B="";

        while(i<n)
        {
            A+='U';
            i++;
        }
        while(j<m)
        {
            B+=target[j];
            j++;
        }

        return A+B;
    }
};