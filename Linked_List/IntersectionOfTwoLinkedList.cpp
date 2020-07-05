// Link: https://leetcode.com/problems/intersection-of-two-linked-lists/

// Write a program to find the node at which the intersection of two singly linked lists begins

// solution
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* rootA=headA;
        ListNode* rootB=headB;
        int lenA=0;
        int lenB=0;
        while(headA!=NULL)
            headA=headA->next,lenA++;
        while(headB!=NULL)
            headB=headB->next,lenB++;
        headA=rootA;
        headB=rootB;
        if(lenA>lenB)
        {
            int no=lenA-lenB;
            while(no--)
                headA=headA->next;
        }
        else
        {
            int no=lenB-lenA;
            while(no--)
                headB=headB->next;
        }
        while(headA && headA!=headB)
        {
            headA=headA->next;
            headB=headB->next;
        }
        return headA;
    }