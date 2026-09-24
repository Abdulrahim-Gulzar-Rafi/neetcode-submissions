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
    void reorderList(ListNode* head) {
        ListNode *temp = head;
        int n = 0;
        while (temp->next != nullptr) {
            temp = temp->next;
            n ++;
        }
        ListNode* tail = temp;
        const int half = n / 2;
        ListNode *mid = head;
        for (int i = 0; i < half; i++) {
            mid = mid->next;
        }
        ListNode *prev = nullptr;
        temp = mid;
        while (temp != nullptr) {
            ListNode *front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        temp = head;
        while (temp != nullptr) {
            ListNode *new_temp = temp->next;
            temp->next = tail;
            ListNode *new_tail = tail->next;
            tail->next = new_temp;
            temp = new_temp;
            tail = new_tail;
        }
    }
};
