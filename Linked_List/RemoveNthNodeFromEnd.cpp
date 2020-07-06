// Link: https://leetcode.com/problems/remove-nth-node-from-end-of-list/

// Given a linked list, remove the n-th node from the end of list and return its head.

// solution
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL || head->next==NULL)
            return NULL;
        ListNode* start=head;
        ListNode* end=head;
        while(n--)
            end=end->next;
        if(end==NULL)
        {
            head=head->next;
            return head;
        }
        while(end!=NULL && end->next!=NULL)
        {
            end=end->next;
            start=start->next;
        }
        ListNode* temp=start->next;
        start->next=start->next->next;
        delete(temp);
        return head;
    }