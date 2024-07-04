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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* curr = head->next;
        ListNode* newHead = head;
        ListNode* prev = head;
        int s = 0;

        while (curr != nullptr) {
            if (curr->val != 0) {
                s += curr->val;
            } else {
                prev = prev->next;
                prev->val = s;
                s = 0;
            }
            curr = curr->next;
        }

        prev->next = nullptr;
        return newHead->next;
    }
};