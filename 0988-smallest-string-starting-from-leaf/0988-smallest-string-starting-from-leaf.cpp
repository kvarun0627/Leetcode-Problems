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

// Function to convert node value to corresponding letter
string getLetter(int val) {
    return string(1, 'a' + val); // Convert value to 'a'-'z'
}

string DFS(TreeNode* root, string current) {
    if (!root) {
        return "";
    }

    // Add the current node's letter to the string
    current = getLetter(root->val) + current;

    // If the node is a leaf, return the current string
    if (!root->left && !root->right) {
        return current;
    }

    // Recursively get strings from left and right subtrees
    string leftString = DFS(root->left, current);
    string rightString = DFS(root->right, current);

    // If one of the strings is empty, return the other one
    if (leftString == "") return rightString;
    if (rightString == "") return leftString;

    // Return the lexicographically smaller string
    return min(leftString, rightString);
}

string smallestFromLeaf(TreeNode* root) {
    return DFS(root, "");
}
};