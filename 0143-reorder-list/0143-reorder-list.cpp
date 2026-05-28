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
        ListNode* slow = head, *fast = head, *p;

        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* head_sec_list = slow;
        // Reverse the second list

        ListNode* prev = NULL, *curr = head_sec_list;

        while(curr) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        head_sec_list = prev;
        // while(head_sec_list) {
        //     cout<<head_sec_list->val<<"\n";
        //     head_sec_list = head_sec_list->next;
        // }
        while(head_sec_list->next != NULL) {
            ListNode* temp = head->next;
            head->next = head_sec_list;
            ListNode* temp2 = head_sec_list->next;
            head_sec_list->next = temp;
            head_sec_list = temp2;
            head = temp;
        }
    }
};