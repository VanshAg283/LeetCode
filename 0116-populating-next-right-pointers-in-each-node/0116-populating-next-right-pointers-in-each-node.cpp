/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void bfs(Node* root) {
        if (!root) {
            return;
        }
        queue<Node*> q;
        q.push(root);
        while(!q.empty()) {
            Node* node = q.front();
            q.pop();
            if (node->left) {
                node->left->next = node->right;
                q.push(node->left);
                if (node->next) {
                    node->right->next = node->next->left;
                }
                q.push(node->right);
            }
        }
    }
    Node* connect(Node* root) {
        bfs(root);
        return root;
    }
};