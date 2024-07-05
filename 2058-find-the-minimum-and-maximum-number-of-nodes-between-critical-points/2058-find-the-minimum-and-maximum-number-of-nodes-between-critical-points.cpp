/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans(2, -1);
        vector<int> indexes;
        int i = 1;
        ListNode* nxt = head->next->next;
        ListNode* curr = head->next;
        ListNode* prev = head;
        while (nxt != nullptr) {
            if (curr->val > prev-> val && curr->val > nxt->val) {
                indexes.push_back(i);
            } if (curr->val < prev-> val && curr->val < nxt->val) {
                indexes.push_back(i);
            }
            i++;
            prev = prev->next;
            curr = curr->next;
            nxt = nxt->next;
        }
        if (indexes.size() == 0 || indexes.size() == 1) {
            return ans;
        }
        ans[1] = indexes[indexes.size() - 1] - indexes[0];
        int md = 100001;
        for (int i = 0; i < indexes.size() - 1; ++i) {
            md = min(md, indexes[i + 1] - indexes[i]);
        }
        ans[0] = md;
        return ans;

    }
};