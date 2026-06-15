class Solution {
public:

    ListNode* deleteMiddle(ListNode* head) {

        // Agar sirf 1 node hai
        if(head->next == NULL)
            return NULL;

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;

        // Slow 1 step chalega
        // Fast 2 step chalega
        while(fast != NULL && fast->next != NULL){

            prev = slow;

            slow = slow->next;

            fast = fast->next->next;
        }

        // Middle node delete
        prev->next = slow->next;

        return head;
    }
};