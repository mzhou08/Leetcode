#include <cstddef>
#include <iostream>

/*
Runtime: 32 ms, faster than 63.73% of C++ online submissions for Add Two Numbers.
Memory Usage: 71.5 MB, less than 10.81% of C++ online submissions for Add Two Numbers.
*/

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* sum = new ListNode();
        ListNode* curr = sum;
        ListNode* l1pos = l1;
        ListNode* l2pos = l2;

        while (l1pos != nullptr && l2pos != nullptr) {
            int curr_sum = curr->val + l1pos->val + l2pos->val;
            curr->val = curr_sum % 10;
            if (curr_sum >= 10) {
                curr->next = new ListNode(curr_sum / 10);
            } else if (l1pos->next != nullptr || l2pos->next != nullptr) {
                curr->next = new ListNode();
            }
            
            curr = curr->next;
            l1pos = l1pos->next;
            l2pos = l2pos->next;
        }

        while (l1pos != nullptr) {
            int curr_sum = curr->val + l1pos->val;
            curr->val = curr_sum % 10;
            if (curr_sum >= 10) {
                curr->next = new ListNode(curr_sum / 10);
            } else if (l1pos->next != nullptr) {
                curr->next = new ListNode();
            }

            curr = curr->next;
            l1pos = l1pos->next;
        }

        while (l2pos != nullptr) {
            int curr_sum = curr->val + l2pos->val;
            curr->val = curr_sum % 10;
            if (curr_sum >= 10) {
                curr->next = new ListNode(curr_sum / 10);
            } else if (l2pos->next != nullptr) {
                curr->next = new ListNode();
            }

            curr = curr->next;
            l2pos = l2pos->next;
        }

        return sum;
    }
};