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
    vector<int> inorder;
private:
    void inOrder(TreeNode* root) {
        if (root) {
            inOrder(root->left);
            inorder.push_back(root->val);
            inOrder(root->right);
        }
    }

    TreeNode* constructBST(int start, int end) {
        if (start > end) return nullptr;
        
        int mid = start + (end - start) / 2;
        TreeNode* node = new TreeNode(inorder[mid]);
        
        node->left = constructBST(start, mid - 1);
        node->right = constructBST(mid + 1, end);
        
        return node;
    }

public:
    TreeNode* balanceBST(TreeNode* root) {
        inOrder(root);
        return constructBST(0, inorder.size() - 1);
    }
};