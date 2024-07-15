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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        TreeNode* root;
        map<int, TreeNode*> mp;
        set<int> st; 
        for (int i = 0; i < descriptions.size(); ++i) {
            if (mp.find(descriptions[i][0]) == mp.end())
                mp[descriptions[i][0]] = new TreeNode(descriptions[i][0]);
            if(mp.find(descriptions[i][1]) == mp.end())
                mp[descriptions[i][1]] = new TreeNode(descriptions[i][1]);
            st.insert(descriptions[i][1]);
        }
        for (int i = 0; i < descriptions.size(); ++i) {
            if (descriptions[i][2]) {
                mp[descriptions[i][0]]->left = mp[descriptions[i][1]];
            } else {
                mp[descriptions[i][0]]->right = mp[descriptions[i][1]];
            }
            if (st.find(descriptions[i][0]) == st.end()) {
                root = mp[descriptions[i][0]];
            }
        }
        return root;
    }
};