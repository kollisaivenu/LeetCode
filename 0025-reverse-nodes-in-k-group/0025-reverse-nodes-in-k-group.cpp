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
        ListNode *newHead = new ListNode(), *toAttach = newHead;

        while(head){
            int groupCount = 1;
            ListNode* endNode = head;

            while(groupCount < k && endNode->next){
                endNode = endNode->next;
                groupCount++;
            }
            if(groupCount<k){
                toAttach->next = head;
                break;
            }
            ListNode* curr = head;
            head = endNode->next;
            endNode->next = NULL;
            ListNode* rev = reverse(curr);

            if(!newHead){
                newHead->next = rev;
                toAttach = toAttach->next;
            } else {
                toAttach->next = rev;
            }

            while(toAttach->next){
                toAttach = toAttach->next;
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