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
    ListNode* reverseListRecursive(ListNode* back, ListNode* head) {
        if (head == nullptr) return back;
        ListNode* front = head->next;
        head->next = back;
        back = head;
        head = front;
        return reverseListRecursive(back, head);
    }
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        return reverseListRecursive(nullptr, head);
    }
};