// Link: https://leetcode.com/problems/linked-list-cycle-ii/

//Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

//To represent a cycle in the given linked list, we use an integer pos which represents the position (0-indexed) 
//in the linked list where tail connects to. If pos is -1, then there is no cycle in the linked list.

//Note: Do not modify the linked list.

// solution
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL || head->next==NULL)
            return NULL;
        ListNode* slow=head->next;
        ListNode* fast=head->next->next;
        int flag=0;
        while(slow!=fast)
        {
            slow=slow->next;
            if(fast==NULL || fast->next==NULL)
            {
                flag=1;
                break;
            }
            fast=fast->next->next;
        }
        if(flag==1)
            return NULL;
        fast=head;
        while(fast!=slow)
        {
            fast=fast->next;
            slow=slow->next;
        }
        return slow;
    }