class Solution {
public:

ListNode* reverse(ListNode* head){

    ListNode* prev=NULL;

    ListNode* curr=head;

    while(curr!=NULL){

        ListNode* nextNode=curr->next;

        curr->next=prev;

        prev=curr;

        curr=nextNode;
    }

    return prev;
}

bool isPalindrome(ListNode* head) {

    ListNode* slow=head;

    ListNode* fast=head;

    while(fast!=NULL && fast->next!=NULL){

        slow=slow->next;

        fast=fast->next->next;
    }

    ListNode* newHead=reverse(slow);

    ListNode* first=head;

    ListNode* second=newHead;

    while(second!=NULL){

        if(first->val!=second->val){

            return false;
        }

        first=first->next;

        second=second->next;
    }

    return true;
}
};