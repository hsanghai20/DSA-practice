// Link: https://leetcode.com/problems/rotate-list/

// Given a linked list, rotate the list to the right by k places, where k is non-negative.

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

    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)
            return head;
        ListNode* temp=head;
        ListNode* newhead=head;
        ListNode* temp1=head;
        int count=0;
        while(temp1)
        {
            count++;
            temp1=temp1->next;
        }
        k=k%count;
        while(k--)
            temp=temp->next;
        while(temp->next)
        {
            head=head->next;
            temp=temp->next;
        }
        temp->next=newhead;
        newhead=head->next;
        head->next=NULL;
        return newhead;
    }
