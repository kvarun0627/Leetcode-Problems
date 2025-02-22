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

    pair<int, int> level(int idx, string& traversal) {
        int lvl = 0;
        while (idx < traversal.size() && traversal[idx] == '-') {
            idx++;
            lvl++;
        }
        return {lvl, idx};
    }

    pair<int, int> cvt_to_num(string& traversal, int idx, int n) {
        int ans = 0;
        while (idx < n && traversal[idx] != '-') {
            ans = ans * 10 + (traversal[idx] - '0');
            idx++;
        }
        return {ans, idx};
    }

    TreeNode* recoverFromPreorder(string traversal) {
        vector<TreeNode*> lvl(1001, nullptr);
        int n = traversal.size();

        auto [val, idx] = cvt_to_num(traversal, 0, n);
        TreeNode* root = new TreeNode(val);
        lvl[0] = root;

        int i = idx;
        while (i < n) {
            auto [l, new_i] = level(i, traversal);
            auto [val, j] = cvt_to_num(traversal, new_i, n);

            TreeNode* node = new TreeNode(val);
            lvl[l] = node;

            TreeNode* parent = lvl[l - 1];
            if (parent->left == nullptr) {
                parent->left = node;
            } else {
                parent->right = node;
            }

            i = j;
        }

        return root;
    }
};