// Link: https://leetcode.com/problems/add-two-numbers/

// You are given two non-empty linked lists representing two non-negative integers. 
//The digits are stored in reverse order and each of their nodes contain a single digit. 
//Add the two numbers and return it as a linked list.

//You may assume the two numbers do not contain any leading zero, except the number 0 itself.

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

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum=(l1?l1->val:0)+(l2?l2->val:0);
        ListNode* ans=new ListNode(sum%10);
        ListNode* root=ans;
        int no=sum/10;
        l1=l1?l1->next:l1;
        l2=l2?l2->next:l2;
        while(l1 || l2 || no)
        {
            int up=l1?l1->val:0;
            int down=l2?l2->val:0;
            ans->next=new ListNode((up+down+no)%10);
            ans=ans->next;
            no=(up+down+no)/10;
            l1=l1?l1->next:l1;
            l2=l2?l2->next:l2;
        }
        return root;
    }

