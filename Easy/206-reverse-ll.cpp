/*
Runtime: 3 ms, faster than 98.31% of C++ online submissions for Reverse Linked List.
Memory Usage: 8.3 MB, less than 80.40% of C++ online submissions for Reverse Linked List.
*/


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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        if (curr != nullptr) {
            ListNode* next = curr->next;

            while (next != nullptr) {
                curr->next = prev;
                prev = curr;
                curr = next;
                next = next->next;
            }

            curr->next = prev;
        }
        
        return curr;
    }
};