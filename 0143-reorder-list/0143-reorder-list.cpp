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
        ListNode *slowPointer = head, *fastPointer = head;

        // Divide the lists into 2 halves
        while(fastPointer->next && fastPointer->next->next){
            slowPointer = slowPointer->next;
            fastPointer = fastPointer->next->next;
        }
        ListNode *firstList = head, *secondList = slowPointer->next;
        slowPointer->next = NULL;

        // Reverse the second list

        ListNode *prev = NULL, *curr = secondList, *next = NULL;

        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        secondList = prev;
        
        while(secondList){
            ListNode* temp1 = firstList->next;
            ListNode* temp2 = secondList->next;
            firstList->next = secondList;
            secondList->next = temp1;
            firstList = temp1;
            secondList = temp2;
        }
    }
};