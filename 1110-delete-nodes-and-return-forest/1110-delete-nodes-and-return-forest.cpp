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
private:
    vector<bool> deleteNodes = vector<bool>(1001,0);
public:
    void traverse(TreeNode*& root, vector<TreeNode*>& res) {
        if (!root) return;
        traverse(root->left, res);
        traverse(root->right, res);
        if (deleteNodes[root->val] == 1) {
            if (root->left) res.push_back(root->left);
            if (root->right) res.push_back(root->right);
            root = NULL;
            delete root;
        }

    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> ans;
        for (int i : to_delete) {
            deleteNodes[i] = true;
        }
        traverse(root, ans);
        if (root) ans.push_back(root);
        return ans;
    }
};