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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *newHead = new ListNode(), *temp = newHead;

        while(head){
            int n = 1;
            ListNode* end = head;
            while(n < k && end->next){
                end = end->next;
                n++;
            }
            if(n<k){
                temp->next = head;
                break;
            }
            ListNode* curr = head;
            head = end->next;
            end->next = NULL;

            if(n == k){
                ListNode* rev = reverse(curr);
                if(!newHead){
                    newHead->next = rev;
                    temp = temp->next;
                } else {
                    temp->next = rev;
                }

                while(temp->next){
                    temp = temp->next;
                }
            }
        }

        return newHead->next;
        
        
    }
    ListNode* reverse(ListNode* head){
        ListNode *curr = head, *prev = NULL, *next = NULL;
        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;

        }
        return prev;
    }
};