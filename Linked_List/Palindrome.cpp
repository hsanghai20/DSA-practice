// Link: https://leetcode.com/problems/palindrome-linked-list/

//Given a singly linked list, determine if it is a palindrome.

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
    ListNode* middle(ListNode* head)
    {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast && fast->next)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
    ListNode* reverse(ListNode* head)
    {
        ListNode* prev=NULL;
        while(head!=NULL)
        {
            ListNode* curr=head->next;
            head->next=prev;
            prev=head;
            head=curr;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* root=head;
        ListNode* mid=middle(head);
        ListNode* last=reverse(mid);
        while(last!=NULL)
        {
            if(last->val!=root->val)
                return false;
            last=last->next;
            root=root->next;
        }
        return true;
    }
