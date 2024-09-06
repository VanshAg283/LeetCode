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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode* dummy = new ListNode();
        ListNode* ans = dummy;
        set<int> s(nums.begin(), nums.end());
        while (head != nullptr) {
            if (s.find(head->val) == s.end()) {
                ans->next = new ListNode(head->val);
                ans = ans->next;
            }
            head = head->next;
        }
        return dummy->next;
    }
};