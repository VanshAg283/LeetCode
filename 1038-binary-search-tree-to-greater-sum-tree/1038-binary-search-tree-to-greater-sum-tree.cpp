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
    void revinOrder(TreeNode* root, int& s) {
        if (root == NULL) {
            return;
        }
        revinOrder(root->right, s);
        s += root->val;
        root->val = s;
        revinOrder(root->left, s);
    }
    TreeNode* bstToGst(TreeNode* root) {
        int s = 0;
        revinOrder(root, s);
        return root;
    }
};