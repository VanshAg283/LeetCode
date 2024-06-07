class TrieNode {
public:
    vector<TrieNode*> children;
    bool isEnd;

    TrieNode() : children(26), isEnd(false) {}
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        TrieNode* root = new TrieNode();
        buildTrie(root, dictionary);

        stringstream ss(sentence);
        string word, result;
        while (ss >> word) {
            result += getRoot(root, word) + " ";
        }

        result.pop_back();
        return result;
    }

    void buildTrie(TrieNode* root, vector<string>& dictionary) {
        for (const string& word : dictionary) {
            TrieNode* node = root;
            for (char c : word) {
                if (!node->children[c - 'a']) {
                    node->children[c - 'a'] = new TrieNode();
                }
                node = node->children[c - 'a'];
            }
            node->isEnd = true;
        }
    }

    string getRoot(TrieNode* root, const string& word) {
        TrieNode* node = root;
        string rootWord;
        for (char c : word) {
            if (!node->children[c - 'a'] || node->isEnd) {
                break;
            }
            node = node->children[c - 'a'];
            rootWord += c;
        }
        return node->isEnd ? rootWord : word;
    }
};