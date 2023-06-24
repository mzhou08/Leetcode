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
    /*
    Contraction Approach

    First merge each pair of lists.
    Call mergeKLists on half the number of lists.
    Return the result.

    Merging two lists:

    */

    ListNode* mergePair(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(-1);
        ListNode* curr = head;

        while (l1 != NULL || l2 != NULL) {
            if (l1 == NULL) {
                curr->next = l2;
                curr = l2;

                l2 = l2->next;
            } else if (l2 == NULL) {
                curr->next = l1;
                curr = l1;

                l1 = l1->next;
            } else if (l1->val < l2->val) {
                curr->next = l1;
                curr = l1;

                l1 = l1->next;
            } else {
                curr->next = l2;
                curr = l2;

                l2 = l2->next;
            }
        }

        ListNode* newHead = head->next;
        delete head;

        return newHead;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) {
            return NULL;
        } else if (lists.size() == 1) {
            return lists[0];
        }

        vector<ListNode*> newLists = {};

        for (int i = 0; i < lists.size() / 2; i++) {
            newLists.push_back(
                mergePair(lists[2*i], lists[2*i + 1])
            );
        }

        if (lists.size() % 2 == 1) {
            newLists.push_back(lists.back());
        }
        
        return mergeKLists(newLists);

    }
};