class Solution {
public:
    
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        
        while (head) {
            ListNode* nextNode = head->next;
            head->next = prev;
            prev = head;
            head = nextNode;
        }
        
        return prev;
    }
    
    int pairSum(ListNode* head) {
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        // Find middle
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // Reverse second half
        ListNode* second = reverseList(slow);
        ListNode* first = head;
        
        int maxi = 0;
        
        while (second) {
            maxi = max(maxi, first->val + second->val);
            
            first = first->next;
            second = second->next;
        }
        
        return maxi;
    }
};