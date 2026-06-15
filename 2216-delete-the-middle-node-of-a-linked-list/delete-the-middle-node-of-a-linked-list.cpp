class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {

        // Agar sirf 1 node hai
        if(head == NULL || head->next == NULL)
            return NULL;

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;

        // Fast 2 step aur slow 1 step chalega
        while(fast != NULL && fast->next != NULL){

            prev = slow;          // slow ke previous ko store karo

            slow = slow->next;    // 1 step

            fast = fast->next->next; // 2 step
        }

        // Middle node delete karo
        prev->next = slow->next;

        return head;
    }
};