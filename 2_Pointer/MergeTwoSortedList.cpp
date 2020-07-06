// Link: https://leetcode.com/problems/merge-two-sorted-lists/ 

// Merge two sorted linked lists and return it as a new sorted list.
// The new list should be made by splicing together the nodes of the first two lists.

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
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL)
            return l2;
        if(l2==NULL)
            return l1;
        ListNode* ans= new ListNode(-1);
        ListNode* root=ans;
        while(l1 && l2)
        {
            if(l1->val>l2->val)
            {
                ans->next=l2;
                l2=l2->next;
            }
            else
            {
                ans->next=l1;
                l1=l1->next;
            }
            ans=ans->next;
        }
        ans->next=l1?l1:l2;
        return root->next;
    }